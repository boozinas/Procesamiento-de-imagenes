#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <Magick++.h>
//#include <armadillo>

class gImage {

public:
	gImage(std::string path);

	Magick::ColorRGB getColor(int x, int y); // Gets the RGB color of the pixel at that point
	int getIntensity(int x, int y); // Gets the luma values of the pixel at that point
	

	void sync(); // Saves any changes to the exisiting image file
	bool save(std::string path); // Saves any changes to a given path

	// Getters
	int getWidth();
	int getHeight();

	std::vector< std::vector< std::vector<float> > > decomposedWindows;
	int windowSize;

private:
	std::string file;
	std::vector< std::vector<int> > imageGradientX;
	std::vector< std::vector<int> > imageGradientY;
	

	int width;
	int height;

	Magick::Image image;
	const Magick::Quantum *pixels;
	//Magick::PixelPacket *pixels;


	void sobel();
	
	//std::vector< std::vector< std::vector<float> > > trimWindows();
	//std::vector< std::vector<float> > flatten(std::vector< std::vector<float> > window);

};