#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <Magick++.h>

using namespace Magick;
//#include <armadillo>

class gImageBajas {
private:
	Magick::Image img;
	float   **imageMatrix, **resultMatrix;
	int width, height;

	double range;

public:

	void filtroSobel();
	void filtroPromedioFacil();
	int filtroPromedioManual();
	int gaussianFilter();
	int writeImage(std::string);
};

void gImageBajas::filtroSobel() {
	Magick::InitializeMagick("");
	char* copy = "C:\\Users\\boozh\\Documents\\8oSemestre\\Analisis_de_Imagenes\\Ejercicios\\ImageOutput_1\\copy.bmp";
	const double kernel[] = { -2, -1, 0, -1, 0, 1, 0, 1, 2 };
	Magick::Image image;
	Magick::ColorRGB px;
	Magick::Color pxsepi;
	image.modifyImage();

	try {
		// Read a file into image object 
		image.read(copy);
		image.type(TrueColorType);
		image.convolve(3, kernel);
		//image.cannyEdge();
		image.syncPixels();
		image.write("C:\\Users\\boozh\\Documents\\8oSemestre\\Analisis_de_Imagenes\\Ejercicios\\ImageOutput_1\\copy_convolucion.bmp");
	}
	catch (Magick::Exception &error_)
	{
		printf("ha ocurrido un error");
		//return 1;
	}
}

void gImageBajas::filtroPromedioFacil() {
	Magick::InitializeMagick("");
	char* copy = "C:\\Users\\boozh\\Documents\\8oSemestre\\Analisis_de_Imagenes\\Ejercicios\\ImageOutput_1\\copy.bmp";
	const double kernel[] = { 1 * 0.11111, 1 * 0.11111, 1 * 0.11111, 1 * 0.11111, 1 * 0.11111, 1 * 0.11111, 1 * 0.11111, 1 * 0.11111, 1 * 0.11111 };
	Magick::Image image;
	Magick::ColorRGB px;
	Magick::Color pxsepi;
	image.modifyImage();

	try {
		// Read a file into image object 
		image.read(copy);
		image.type(TrueColorType);
		image.convolve(3, kernel);
		image.syncPixels();
		image.write("C:\\Users\\boozh\\Documents\\8oSemestre\\Analisis_de_Imagenes\\Ejercicios\\ImageOutput_1\\copy_convolucion_prom.bmp");
	}
	catch (Magick::Exception &error_)
	{
		printf("ha ocurrido un error");
		//return 1;
	}
}



int gImageBajas::filtroPromedioManual() {
	Magick::InitializeMagick("");
	Magick::Image image;
	image.read("C:\\Users\\boozh\\Documents\\8oSemestre\\Analisis_de_Imagenes\\Ejercicios\\ImageOutput_1\\copy.bmp");
	this->img = image;
	try {

		image.type(Magick::GrayscaleType);
		image.modifyImage();

		int w = image.columns(), h = image.rows();
		int row = 0, column = 0;
		int range = 256; //pow(2, image.modulusDepth());
		const Magick::Quantum *pixels;
		pixels = image.getConstPixels(0, 0, w, h);


		// creating the pixel matrix
		this->imageMatrix = new float*[h]; for (int i = 0; i < h; ++i) this->imageMatrix[i] = new float[w];
		this->resultMatrix = new float*[h]; for (int i = 0; i < h; ++i) this->resultMatrix[i] = new float[w];
		

		// storing meta data
		this->width = w; this->height = h;
		this->range = range;

		float pVal = 0;
		for (row = 0; row < h; row++)
		{
			for (column = 0; column < w; column++)
			{
				//Magick::Color color;
				
				unsigned offset = image.channels() * (width * w + h);
				///////////////////////////777
					unsigned int r = 255 * QuantumScale * *(pixels + (row * 4) + 0);
					unsigned int g = 255 * QuantumScale * *(pixels + (row * 4) + 1);
					unsigned int b = 255 * QuantumScale * *(pixels + (row * 4) + 2);
			
				Magick::Color color = Magick::Color(r,g,b);
				///////////////////////////////7
				//color = (pixels[offset +0], pixels[offset + 1], pixels[offset + 3]);
				//Magick::Color color = pixels[w * row + column];
				pVal = (color.quantumRed() / range) / 256;
				printf("pVal : %d", pVal);
				//pVal = (color.redQuantum() / range) / 256;
				this->imageMatrix[row][column] = pVal;
				this->resultMatrix[row][column] = pVal;
			}
			//std::cout<< std::endl;
		}

	}
	catch (std::exception &error_) {
		std::cout << "Caught exception: " << error_.what() << std::endl;
		return 1;
	}
	gaussianFilter();
	writeImage("C:\\Users\\boozh\\Documents\\8oSemestre\\Analisis_de_Imagenes\\Ejercicios\\ImageOutput_1\\copy_convolucion_prom_mano.bmp");
	return 0;
}

int gImageBajas::gaussianFilter() {

	/**
	 *          | 1 4  7  4  1 |
	 *          | 4 16 26 16 4 |
	 *    1/273 | 7 26 41 26 7 |
	 *          | 4 16 26 16 4 |
	 *          | 1 4  7  4  1 |
	 *
	 **/
	float kernel[5][5] = {
								{ 1, 4,  7,  4,  1 },
								{ 4, 16, 26, 16, 4 },
								{ 7, 26, 41, 26, 7 },
								{ 4, 16, 26, 16, 4 },
								{ 1, 4,  7,  4,  1 }
	};

	for (int row = 0; row < (this->height); row++)
	{
		for (int column = 0; column < (this->width); column++)
		{
			float pSum = 0;
			if ((row >= (this->height) - 5) || (column >= (this->width) - 5)) {

				this->resultMatrix[row][column] = this->imageMatrix[row][column];

			}
			else {

				for (int kernelRow = 0; kernelRow < 5; kernelRow++)
				{
					for (int kernelColumn = 0; kernelColumn < 5; kernelColumn++)
					{
						pSum += (float)(this->imageMatrix[row + kernelRow][column + kernelColumn] * kernel[kernelRow][kernelColumn]);
					}
				}
				this->resultMatrix[row][column] = (pSum / 273);
			}
		}
	}
	return 0;
}
int gImageBajas::writeImage(std::string path) {

	Magick::Image image;
	image = this->img;
	image.modifyImage();
	image.type(Magick::TrueColorType);
	ssize_t columns = this->width;
	Magick::Quantum *pixel_cache;
	pixel_cache = image.getPixels(0, 0, this->width, this->height);

	for (int i = 0; i < this->width; i++)
	{
		for (int j = 0; j < this->height; j++)
		{
			float pVal = this->resultMatrix[j][i];
			Magick::ColorGray gColor(pVal);
			
			Magick::Quantum *pixel =pixel_cache + j * columns + i;
	
			pixel[0] = gColor.quantumRed();
			pixel[1] = gColor.quantumGreen();
			pixel[2] = gColor.quantumBlue();
			pixel[3] = gColor.quantumAlpha();

			//pixel = gColor.~ColorGray;
		}
	}
	image.syncPixels();
	image.write(path);

	return 0;
}
