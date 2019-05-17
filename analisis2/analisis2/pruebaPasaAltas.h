#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <Magick++.h>

using namespace Magick;
//#include <armadillo>

class gImageAltas {

public:

	void filtroSobel();
	void filtroPromedio();
};

void gImageAltas:: filtroSobel() {
	Magick::InitializeMagick("");
	char* copy = "C:\\Users\\boozh\\Documents\\8oSemestre\\Analisis_de_Imagenes\\Ejercicios\\ImageOutput_1\\copy.bmp";
	const double kernel[] = { -2, -1, 0, -1, 0, 1, 0, 1, 2};
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

void gImageAltas::filtroPromedio() {
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