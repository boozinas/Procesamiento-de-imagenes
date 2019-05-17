#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
//#include<gdiplus.h>
//#include<gdiplusbitmap.h>
//#include<gdiplusheaders.h>
#include <objidl.h>
#include <iostream>
#include <Magick++.h>
//using namespace std;
using namespace Magick;
#define MAX_COLOR 255
#define FACTOR_BRILLO 25
class OpPuntual
{
private:

public:
	unsigned char imageHeader[54]; // para obtener la cabecera
	unsigned char colorTable[1024]; // para obtener la tabla de colores
	OpPuntual() {}
	FILE* fp;
	FILE* fo;
	unsigned char *imageData;
	unsigned char *newimageData;
	int bitDepth;
	int imgDataSize;
	int height;
	int width;
	void Negativo();
	void Brillo(int brillo);
	void Binarizar(int umbral);
	//Color
	void Sepia();
	void Grises();
	void Red();
	void Green();
	void Blue();

	void ObtenerCabecera(char argv[]);
	//void ObtenerCabeceraColor(char argv[]);
	~OpPuntual() {}
};

void OpPuntual::Negativo()
{
	ObtenerCabecera("C:\\Users\\boozh\\Documents\\8oSemestre\\Analisis_de_Imagenes\\Ejercicios\\ImageOutput_1\\copy_tratamiento.bmp");

	int i, j;
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			newimageData[i*width + j] = 255 - imageData[i*width + j];
			//newimageData[i*width + j] = imageData[i*width + j] + 50;

		}
	}
	fo = fopen("C:\\Users\\boozh\\Documents\\8oSemestre\\Analisis_de_Imagenes\\Ejercicios\\ImageOutput_1\\copy_tratamiento.bmp", "wb");
	fwrite(imageHeader, sizeof(unsigned char), 54, fo);
	if (bitDepth <= 8)	// Si hay tabla de colores
		fwrite(colorTable, sizeof(unsigned char), 1024, fo);
	fwrite(newimageData, sizeof(unsigned char), imgDataSize, fo); // Escribir los valores de la imagen negativa
	fclose(fo);
	fclose(fp);
	free(imageData);
	free(newimageData);
}

void OpPuntual::Brillo(int brillo)
{
	int i, j, temp;
	ObtenerCabecera("C:\\Users\\boozh\\Documents\\8oSemestre\\Analisis_de_Imagenes\\Ejercicios\\ImageOutput_1\\copy.bmp");

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			//newimageData[i*width + j] = 255 - imageData[i*width + j];
			temp = imageData[i*width + j] + brillo;
			if (temp >= MAX_COLOR)
				newimageData[i*width + j] = MAX_COLOR;
			else if (temp <= 0)
				newimageData[i*width + j] = 0;
			else
				newimageData[i*width + j] = temp;

		}
	}

	fo = fopen("C:\\Users\\boozh\\Documents\\8oSemestre\\Analisis_de_Imagenes\\Ejercicios\\ImageOutput_1\\copy_tratamiento.bmp", "wb");
	fwrite(imageHeader, sizeof(unsigned char), 54, fo);
	if (bitDepth <= 8)	// Si hay tabla de colores
		fwrite(colorTable, sizeof(unsigned char), 1024, fo);
	fwrite(newimageData, sizeof(unsigned char), imgDataSize, fo); // Escribir los valores de la imagen negativa
	fclose(fo);
	fclose(fp);
	free(imageData);
	free(newimageData);
}

void OpPuntual::Binarizar(int umbral) {
	int i, j, temp;
	ObtenerCabecera("C:\\Users\\boozh\\Documents\\8oSemestre\\Analisis_de_Imagenes\\Ejercicios\\ImageOutput_1\\copy.bmp");

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			//newimageData[i*width + j] = 255 - imageData[i*width + j];
			if (imageData[i*width + j ] < umbral)
				newimageData[i*width + j] = 0;
			else
				newimageData[i*width + j] = 255;

		}
	}
	fo = fopen("C:\\Users\\boozh\\Documents\\8oSemestre\\Analisis_de_Imagenes\\Ejercicios\\ImageOutput_1\\copy_tratamiento.bmp", "wb");
	fwrite(imageHeader, sizeof(unsigned char), 54, fo);
	if (bitDepth <= 8)	// Si hay tabla de colores
		fwrite(colorTable, sizeof(unsigned char), 1024, fo);
	fwrite(newimageData, sizeof(unsigned char), imgDataSize, fo); // Escribir los valores de la imagen negativa
	fclose(fo);
	fclose(fp);
	free(imageData);
	free(newimageData);

}

//Operaciones en imagenes a color

void OpPuntual::Sepia() {
		fp = fopen("C:\\Users\\boozh\\Documents\\8oSemestre\\Analisis_de_Imagenes\\Ejercicios\\ImageOutput_1\\copy.bmp", "rb");					//Input File name
		fo = fopen("C:\\Users\\boozh\\Documents\\8oSemestre\\Analisis_de_Imagenes\\Ejercicios\\ImageOutput_1\\copy_tratamiento.bmp", "wb");		    		//Output File name

		int i, r, g, b;
		unsigned char byte[54];

		if (fp == NULL)												// check if the input file has not been opened succesfully.
		{
			printf("File does not exist.\n");
		}

		for (i = 0; i < 54; i++)											//read the 54 byte header from fIn
		{
			byte[i] = getc(fp);
		}

		fwrite(byte, sizeof(unsigned char), 54, fo);					//write the header back

		// extract image height, width and bitDepth from imageHeader 
		int height = *(int*)&byte[18];
		int width = *(int*)&byte[22];
		int bitDepth = *(int*)&byte[28];

		printf("width: %d\n", width);
		printf("height: %d\n", height);

		int size = height * width;									//calculate image size
		printf("tamaño es %d\n", size);
		if (bitDepth == 24) {
		//unsigned char buffer[262144][3];								//to store the image data
		unsigned char* buffer = new unsigned char[size * 3];
		//int a, x;

		for (i = 0; i < size; i++) {
			r = 0;
			g = 0;
			b = 0;
			buffer[i * 3] = getc(fp);									//blue
			buffer[i * 2] = getc(fp);									//green
			buffer[i * 1] = getc(fp);									//red


			//conversion formula of rgb to sepia
			r = (buffer[i * 1] * 0.393) + (buffer[i * 2] * 0.769) + (buffer[i * 3] * 0.189);
			g = (buffer[i * 1] * 0.349) + (buffer[i * 2] * 0.686) + (buffer[i * 3] * 0.168);
			b = (buffer[i * 1] * 0.272) + (buffer[i * 2] * 0.534) + (buffer[i * 3] * 0.131);

			if (r >= MAX_COLOR) {											//if value exceeds
				r = MAX_COLOR;
			}
			if (g >= MAX_COLOR) {
				g = MAX_COLOR;
			}
			if (b >= MAX_COLOR) {
				b = MAX_COLOR;
			}
			putc(b, fo);
			putc(g, fo);
			putc(r, fo);

		}


		fclose(fp);
		fclose(fo);
	}
	else {
			fclose(fp);
			fclose(fo);
		Magick::InitializeMagick("");
		char* copy = "C:\\Users\\boozh\\Documents\\8oSemestre\\Analisis_de_Imagenes\\Ejercicios\\ImageOutput_1\\copy.bmp";
		Magick::Image image;
		ColorRGB px;
		Color pxsepi;
		image.modifyImage();

		try {
			// Read a file into image object 
			image.read(copy);
			image.type(TrueColorType);
			for (int i = 0; i < height; i++)
			{
				for (int j = 0; j < width; j++)
				{
					px = image.pixelColor(i, j);
					r = (px.quantumRed() * 0.393)+ (px.quantumGreen() * 0.769) + (px.quantumBlue() * 0.189);
					g = (px.quantumRed() * 0.349) + (px.quantumGreen() * 0.686) + (px.quantumBlue() * 0.168);
					b = (px.quantumRed() * 0.272) + (px.quantumGreen() * 0.534) + (px.quantumBlue() * 0.131);
					if (r >= MAX_COLOR) {											//if value exceeds
						r = MAX_COLOR;
					}
					if (g >= MAX_COLOR) {
						g = MAX_COLOR;
					}
					if (b >= MAX_COLOR) {
						b = MAX_COLOR;
					}
					/*
					pxsepi.red = (px.red* 0.393) + (px.green * 0.769) + (px.blue * 0.189);
					pxsepi.green = (px.red * 0.349) + (px.green * 0.686) + (px.blue * 0.168);
					pxsepi.blue = (px.red * 0.272) + (px.green * 0.534) + (px.blue * 0.131);*/
					image.pixelColor(i, j, Magick::Color(r, g,b));
						
				}
			}
			printf("la R es : %d", r);
			image.syncPixels();
			image.write("C:\\Users\\boozh\\Documents\\8oSemestre\\Analisis_de_Imagenes\\Ejercicios\\ImageOutput_1\\copy_tratamiento.bmp");
		}
		catch (Magick::Exception &error_)
		{
			printf("caca");
			//return 1;
		}



	}


}

void OpPuntual::Grises() {
	if (bitDepth == 24) {
		fp = fopen("C:\\Users\\boozh\\Documents\\8oSemestre\\Analisis_de_Imagenes\\Ejercicios\\ImageOutput_1\\copy.bmp", "rb");					//Input File name
		fo = fopen("C:\\Users\\boozh\\Documents\\8oSemestre\\Analisis_de_Imagenes\\Ejercicios\\ImageOutput_1\\copy_tratamiento.bmp", "wb");		    		//Output File name

		int i, r, g, b;
		unsigned char byte[54];

		if (fp == NULL)												// check if the input file has not been opened succesfully.
		{
			printf("File does not exist.\n");
		}

		for (i = 0; i < 54; i++)											//read the 54 byte header from fIn
		{
			byte[i] = getc(fp);
		}

		fwrite(byte, sizeof(unsigned char), 54, fo);					//write the header back

		// extract image height, width and bitDepth from imageHeader 
		int height = *(int*)&byte[18];
		int width = *(int*)&byte[22];
		int bitDepth = *(int*)&byte[28];

		printf("width: %d\n", width);
		printf("height: %d\n", height);

		int size = height * width;									//calculate image size
		printf("tamaño es %d\n", size);
		//unsigned char buffer[262144][3];								//to store the image data
		unsigned char* buffer = new unsigned char[size * 3];
		//int a, x;

		for (i = 0; i < size; i++) {
			r = 0;
			g = 0;
			b = 0;
			buffer[i * 3] = getc(fp);									//blue
			buffer[i * 2] = getc(fp);									//green
			buffer[i * 1] = getc(fp);									//red


			//conversion formula of rgb to gray
			r = (buffer[i * 1] + buffer[i * 2] + buffer[i * 3]) / 3;
			g = (buffer[i * 1] + buffer[i * 2] + buffer[i * 3]) / 3;
			b = (buffer[i * 1] + buffer[i * 2] + buffer[i * 3]) / 3;

			if (r >= MAX_COLOR) {											//if value exceeds
				r = MAX_COLOR;
			}
			if (g >= MAX_COLOR) {
				g = MAX_COLOR;
			}
			if (b >= MAX_COLOR) {
				b = MAX_COLOR;
			}
			putc(b, fo);
			putc(g, fo);
			putc(r, fo);

		}


		fclose(fp);
		fclose(fo);
	}
	else {
		//InitializeMagick(*argv);
		Magick::InitializeMagick("");
		char* copy = "C:\\Users\\boozh\\Documents\\8oSemestre\\Analisis_de_Imagenes\\Ejercicios\\ImageOutput_1\\copy.bmp";
		Magick::Image imagen;
		try {
			imagen.read(copy);
			imagen.type(Magick::GrayscaleType);
			imagen.write("C:\\Users\\boozh\\Documents\\8oSemestre\\Analisis_de_Imagenes\\Ejercicios\\ImageOutput_1\\copy_tratamiento.bmp");
		}
		catch (Magick::Exception &error_)
		{
			printf("caca");
			//return 1;
		}
		
	}

}

void OpPuntual::Red() {
	fp = fopen("C:\\Users\\boozh\\Documents\\8oSemestre\\Analisis_de_Imagenes\\Ejercicios\\ImageOutput_1\\copy.bmp", "rb");					//Input File name
	fo = fopen("C:\\Users\\boozh\\Documents\\8oSemestre\\Analisis_de_Imagenes\\Ejercicios\\ImageOutput_1\\copy_tratamiento.bmp", "wb");		    		//Output File name

	int i, r, g, b;
	unsigned char byte[54];

	if (fp == NULL)												// check if the input file has not been opened succesfully.
	{
		printf("File does not exist.\n");
	}

	for (i = 0; i < 54; i++)											//read the 54 byte header from fIn
	{
		byte[i] = getc(fp);
	}

	fwrite(byte, sizeof(unsigned char), 54, fo);					//write the header back

	// extract image height, width and bitDepth from imageHeader 
	int height = *(int*)&byte[18];
	int width = *(int*)&byte[22];
	int bitDepth = *(int*)&byte[28];

	printf("width: %d\n", width);
	printf("height: %d\n", height);

	int size = height * width;									//calculate image size
	printf("tamaño es %d\n", size);
	//unsigned char buffer[262144][3];								//to store the image data
	unsigned char* buffer = new unsigned char[size * 3];
	//int a, x;
	int red;
	if (bitDepth == 24) {
		for (i = 0; i < size; i++) {
			r = 0;
			g = 0;
			b = 0;
			buffer[i * 3] = getc(fp);									//blue
			buffer[i * 2] = getc(fp);									//green
			buffer[i * 1] = getc(fp);									//red


			//conversion formula of rgb to gray
			r = buffer[i * 1];
			g = 0;
			b = 0;

			if (r >= MAX_COLOR) {											//if value exceeds
				r = MAX_COLOR;
			}
			if (g >= MAX_COLOR) {
				g = MAX_COLOR;
			}
			if (b >= MAX_COLOR) {
				b = MAX_COLOR;
			}
			putc(b, fo);
			putc(g, fo);
			putc(r, fo);

		}


		fclose(fp);
		fclose(fo);
	}
	else {
		fclose(fp);
		fclose(fo);
		//InitializeMagick(*argv);
		Magick::InitializeMagick("");
		char* copy = "C:\\Users\\boozh\\Documents\\8oSemestre\\Analisis_de_Imagenes\\Ejercicios\\ImageOutput_1\\copy.bmp";
		Magick::Image image;
		ColorRGB px;
		Magick::pixelColorImage *pixelcolor;
		image.modifyImage();

		try {
			// Read a file into image object 
			image.read(copy);
			image.type(TrueColorType);
			for (int i = 0; i < height; i++)
			{
				for (int j = 0; j < width; j++)
				{
					px = image.pixelColor(i, j);
					image.pixelColor(i, j, Color(px.quantumRed() , px.quantumGreen()*0, px.quantumBlue()*0, px.quantumAlpha()));
				}
			}
			image.syncPixels();
			image.write("C:\\Users\\boozh\\Documents\\8oSemestre\\Analisis_de_Imagenes\\Ejercicios\\ImageOutput_1\\copy_tratamiento.bmp");
		}
		catch (Magick::Exception &error_)
		{
			printf("caca");
			//return 1;
		}



	}
}
void OpPuntual::Green() {
	fp = fopen("C:\\Users\\boozh\\Documents\\8oSemestre\\Analisis_de_Imagenes\\Ejercicios\\ImageOutput_1\\copy.bmp", "rb");					//Input File name
	fo = fopen("C:\\Users\\boozh\\Documents\\8oSemestre\\Analisis_de_Imagenes\\Ejercicios\\ImageOutput_1\\copy_tratamiento.bmp", "wb");		    		//Output File name

	int i, r, g, b;
	unsigned char byte[54];

	if (fp == NULL)												// check if the input file has not been opened succesfully.
	{
		printf("File does not exist.\n");
	}

	for (i = 0; i < 54; i++)											//read the 54 byte header from fIn
	{
		byte[i] = getc(fp);
	}

	fwrite(byte, sizeof(unsigned char), 54, fo);					//write the header back

	// extract image height, width and bitDepth from imageHeader 
	int height = *(int*)&byte[18];
	int width = *(int*)&byte[22];
	int bitDepth = *(int*)&byte[28];

	printf("width: %d\n", width);
	printf("height: %d\n", height);

	int size = height * width;									//calculate image size
	printf("tamaño es %d\n", size);
	//unsigned char buffer[262144][3];								//to store the image data
	unsigned char* buffer = new unsigned char[size * 3];
	//int a, x;
	int green;
	if (bitDepth == 24) {
		for (i = 0; i < size; i++) {
			r = 0;
			g = 0;
			b = 0;
			buffer[i * 3] = getc(fp);									//blue
			buffer[i * 2] = getc(fp);									//green
			buffer[i * 1] = getc(fp);									//red


			//conversion formula of rgb to gray
			r = 0;
			g = buffer[i * 2];
			b = 0;

			if (r >= MAX_COLOR) {											//if value exceeds
				r = MAX_COLOR;
			}
			if (g >= MAX_COLOR) {
				g = MAX_COLOR;
			}
			if (b >= MAX_COLOR) {
				b = MAX_COLOR;
			}
			putc(b, fo);
			putc(g, fo);
			putc(r, fo);

		}
	}
	else {
		fclose(fp);
		fclose(fo);
		//InitializeMagick(*argv);
		Magick::InitializeMagick("");
		char* copy = "C:\\Users\\boozh\\Documents\\8oSemestre\\Analisis_de_Imagenes\\Ejercicios\\ImageOutput_1\\copy.bmp";
		Magick::Image image;
		ColorRGB px;
		Magick::pixelColorImage *pixelcolor;
		image.modifyImage();

		try {
			// Read a file into image object 
			image.read(copy);
			image.type(TrueColorType);
			for (int i = 0; i < height; i++)
			{
				for (int j = 0; j < width; j++)
				{
					px = image.pixelColor(i, j);
					image.pixelColor(i, j, Color(px.quantumRed() * 0, px.quantumGreen(), px.quantumBlue() * 0, px.quantumAlpha()));
				}
			}
			image.syncPixels();
			image.write("C:\\Users\\boozh\\Documents\\8oSemestre\\Analisis_de_Imagenes\\Ejercicios\\ImageOutput_1\\copy_tratamiento.bmp");
		}
		catch (Magick::Exception &error_)
		{
			printf("caca");
			//return 1;
		}



	}

}

void OpPuntual::Blue() {
	fp = fopen("C:\\Users\\boozh\\Documents\\8oSemestre\\Analisis_de_Imagenes\\Ejercicios\\ImageOutput_1\\copy.bmp", "rb");					//Input File name
	fo = fopen("C:\\Users\\boozh\\Documents\\8oSemestre\\Analisis_de_Imagenes\\Ejercicios\\ImageOutput_1\\copy_tratamiento.bmp", "wb");		    		//Output File name

	int i, r, g, b;
	unsigned char byte[54];

	if (fp == NULL)												// check if the input file has not been opened succesfully.
	{
		printf("File does not exist.\n");
	}

	for (i = 0; i < 54; i++)											//read the 54 byte header from fIn
	{
		byte[i] = getc(fp);
	}
	//byte[28] = 24;

	fwrite(byte, sizeof(unsigned char), 54, fo);					//write the header back

	// extract image height, width and bitDepth from imageHeader 
	int height = *(int*)&byte[18];
	int width = *(int*)&byte[22];
	int bitDepth = *(int*)&byte[28];

	printf("width: %d\n", width);
	printf("height: %d\n", height);

	int size = height * width;									//calculate image size
	printf("tamano es %d\n", size);
	//unsigned char buffer[262144][3];								//to store the image data
	unsigned char* buffer = new unsigned char[size * 3];
	unsigned char* buffer_8 = new unsigned char[size];
	unsigned char blue;
	//int a, x;
	if (bitDepth == 24) {
		for (i = 0; i < size; i++) {
			r = 0;
			g = 0;
			b = 0;
			buffer[i * 3] = getc(fp);									//blue
			buffer[i * 2] = getc(fp);									//green
			buffer[i * 1] = getc(fp);									//red


			//conversion formula of rgb to gray
			r = 0;
			g = 0;
			b = buffer[i * 3];

			if (r >= MAX_COLOR) {											//if value exceeds
				r = MAX_COLOR;
			}
			if (g >= MAX_COLOR) {
				g = MAX_COLOR;
			}
			if (b >= MAX_COLOR) {
				b = MAX_COLOR;
			}
			putc(b, fo);
			putc(g, fo);
			putc(r, fo);


		}

		fclose(fp);
		fclose(fo);
	}
	else{
		fclose(fp);
		fclose(fo);
		//InitializeMagick(*argv);
		Magick::InitializeMagick("");
		char* copy = "C:\\Users\\boozh\\Documents\\8oSemestre\\Analisis_de_Imagenes\\Ejercicios\\ImageOutput_1\\copy.bmp";
		Magick::Image image;
		ColorRGB px;
		Magick::pixelColorImage *pixelcolor;
		image.modifyImage();

		try {
			// Read a file into image object 
			image.read(copy);
			image.type(TrueColorType);
			for (int i = 0; i < height; i++)
			{
				for (int j = 0; j < width; j++)
				{
					px = image.pixelColor(i, j);
					image.pixelColor(i, j, Color(px.quantumRed()*0, px.quantumGreen()*0, px.quantumBlue(), px.quantumAlpha()));
				}
			}
			image.syncPixels();
			image.write("C:\\Users\\boozh\\Documents\\8oSemestre\\Analisis_de_Imagenes\\Ejercicios\\ImageOutput_1\\copy_tratamiento.bmp");
		}
		catch (Magick::Exception &error_)
		{
			printf("caca");
			//return 1;
		}



	}
}




void OpPuntual::ObtenerCabecera(char argv[]) {
	fp = fopen(argv, "rb");
	fread(imageHeader, sizeof(unsigned char), 54, fp);
	width = *(int*)&imageHeader[18];
	height = *(int*)&imageHeader[22];
	bitDepth = *(int*)&imageHeader[28];
	imgDataSize = height * width; // tamaño de la imagen

	imageData = (unsigned char*)malloc(imgDataSize * sizeof(unsigned char)); // apartar un bloque de memoria del tamaño de la imagen
	newimageData = (unsigned char*)malloc(imgDataSize * sizeof(unsigned char));

	if (bitDepth <= 8)	// Si hay tabla de colores
		fread(colorTable, sizeof(unsigned char), 1024, fp); // leer los 1024 bits de la tabla de colores

	fread(imageData, sizeof(unsigned char), imgDataSize, fp);
}
