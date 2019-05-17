#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include <vector>
#include <map>
#include <iomanip> 
#include <cmath>
#include <utility>
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
#include <Magick++.h>
#include <string>
#include <iostream>
#include <iomanip>
#if defined(USE_VECTOR)
#  include <vector>
#  include <utility>
#endif
#if defined(USE_MAP)
#  include <map>
#endif
//
//template <class Container >
//void colorHistogram(Container *histogram_, const Image image)


class histograma
{
private:

public:
	int height;
	int width;
	int brillo[256];
	int red[256];
	int blue[256];
	int green[256];
	//void histograma::mostrar(int /*argc*/, char ** argv) {}
	histograma() {}
	//void ObtenerCabeceraColor(char argv[]);
	~histograma() {}
};

/*
void histograma::mostrar() {
	InitializeMagick(*argv);
	Magick::InitializeMagick("");
	char* copy = "C:\\Users\\boozh\\Documents\\8oSemestre\\Analisis_de_Imagenes\\Ejercicios\\ImageOutput_1\\copy.bmp";
	Magick::Image image;
	MagickCore::Image blur;
	long a=3;
	ColorRGB px;
	Color pxsepi;
	ExceptionInfo *exception;
	//GetImageHistogram(blur,a, exception);
	image.modifyImage();

	try {
		// Read a file into image object 
		image.read(copy);
		height = image.columns();
		width = image.rows();
		image.type(TrueColorType);
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				px = image.pixelColor(i, j);
				brillo[px.quantumAlpha()] +=1 ;
				red[px.quantumRed()] += 1;
				green[px.quantumGreen()] += 1;    
				blue[px.quantumBlue()] += 1;
			}
		}

		//for(int j=0; j <)
		
	}
	catch (Magick::Exception &error_){
		printf("caca");
		//return 1;
	}
	


}*/
