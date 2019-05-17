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
#define MAX_COLOR 255
#define MIN_COLOR 0
using namespace Magick;
class OpAritmetica
{
private:
public:
	int height;
	int width;
	void suma();
	void resta();
};

void OpAritmetica::suma() {
	Magick::InitializeMagick("");
	char* copy = "C:\\Users\\boozh\\Documents\\8oSemestre\\Analisis_de_Imagenes\\Ejercicios\\ImageOutput_1\\copy.bmp";
	char* copy_arith = "C:\\Users\\boozh\\Documents\\8oSemestre\\Analisis_de_Imagenes\\Ejercicios\\ImageOutput_1\\copy_arith.bmp";
	Magick::Image image1;
	Magick::Image image2;
	//Magick::Image image3;

	int r, g, b;

	ColorRGB px1;
	ColorRGB px2;
	//Color pxsepi;
	//ColorMono pxmono;

	//Magick::pixelColorImage *pixelcolor;
	
	image1.modifyImage();
	//image2.modifyImage();
	//image3.modifyImage();
	try {
		// Read a file into image object 

		image1.read(copy);
		image2.read(copy_arith);
		image1.type(TrueColorType);
		image2.type(TrueColorType);
		//image3.type(TrueColorType);
		
		int height1 = image1.columns();
		int width1 = image1.rows();

		int height2 = image2.columns();
		int width2 = image2.rows();

		if (height1 >= height2) {
			height = height1;
		}

		else{
			height = height2;
		}

		if (width1 >= width2){
			width = width1;
		}
		else{
			width = width2;
		}
		Geometry newSize = Geometry(height, width);
		newSize.aspect(true);
		image1.resize(Magick::Geometry(newSize));
		image2.resize(Magick::Geometry(newSize));
		image2.write("C:\\Users\\boozh\\Documents\\8oSemestre\\Analisis_de_Imagenes\\Ejercicios\\ImageOutput_1\\copy_suma.bmp");
		printf("no lo se  \n");

		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++) {

				px1 = image1.pixelColor(i, j);
				px2 = image2.pixelColor(i, j);

				r = px1.quantumRed() + px2.quantumRed();
				g = px1.quantumGreen() + px2.quantumGreen();
				b = px1.quantumBlue() + px2.quantumBlue();
				
				if (r >= MAX_COLOR) {											//if value exceeds
					r = MAX_COLOR;
				}
				if (g >= MAX_COLOR) {
					g = MAX_COLOR;
				}
				if (b >= MAX_COLOR) {
					b = MAX_COLOR;
				}

				image2.pixelColor(i, j, Magick::Color(r, g, b));
			}
		}
		image2.syncPixels();
		//image1.threshold(100);
		image2.write("C:\\Users\\boozh\\Documents\\8oSemestre\\Analisis_de_Imagenes\\Ejercicios\\ImageOutput_1\\copy_tratamiento.bmp");
		//image1.write(&blob);
	}
	catch (Magick::Exception &error_) {
		printf("un intento, vaya");
	}
}

void OpAritmetica::resta() {
	Magick::InitializeMagick("");
	char* copy = "C:\\Users\\boozh\\Documents\\8oSemestre\\Analisis_de_Imagenes\\Ejercicios\\ImageOutput_1\\copy.bmp";
	char* copy_arith = "C:\\Users\\boozh\\Documents\\8oSemestre\\Analisis_de_Imagenes\\Ejercicios\\ImageOutput_1\\copy_arith.bmp";
	Magick::Image image1;
	Magick::Image image2;

	int r, g, b;

	ColorRGB px1;
	ColorRGB px2;
	image1.modifyImage();
	try {

		image1.read(copy);
		image2.read(copy_arith);
		image1.type(TrueColorType);
		image2.type(TrueColorType);
		//image3.type(TrueColorType);

		int height1 = image1.columns();
		int width1 = image1.rows();

		int height2 = image2.columns();
		int width2 = image2.rows();

		if (height1 >= height2) {
			height = height1;
		}

		else {
			height = height2;
		}

		if (width1 >= width2) {
			width = width1;
		}
		else {
			width = width2;
		}
		Geometry newSize = Geometry(height, width);
		newSize.aspect(true);
		image1.resize(Magick::Geometry(newSize));
		image2.resize(Magick::Geometry(newSize));
		image2.write("C:\\Users\\boozh\\Documents\\8oSemestre\\Analisis_de_Imagenes\\Ejercicios\\ImageOutput_1\\copy_suma.bmp");
		printf("no lo se  \n");

		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++) {

				px1 = image1.pixelColor(i, j);
				px2 = image2.pixelColor(i, j);

				r = px1.quantumRed() - px2.quantumRed();
				g = px1.quantumGreen() - px2.quantumGreen();
				b = px1.quantumBlue() - px2.quantumBlue();

				if (r <= MIN_COLOR) {											//if value exceeds
					r = MIN_COLOR;
				}
				if (g <= MIN_COLOR) {
					g = MIN_COLOR;
				}
				if (b <= MIN_COLOR) {
					b = MIN_COLOR;
				}

				image2.pixelColor(i, j, Magick::Color(r, g, b));
			}
		}
		image2.syncPixels();
		//image1.threshold(100);
		image2.write("C:\\Users\\boozh\\Documents\\8oSemestre\\Analisis_de_Imagenes\\Ejercicios\\ImageOutput_1\\copy_tratamiento.bmp");
		//image1.write(&blob);
	}
	catch (Magick::Exception &error_) {
		printf("un intento, vaya");
	}
}