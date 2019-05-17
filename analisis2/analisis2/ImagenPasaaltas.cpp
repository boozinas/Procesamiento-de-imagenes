#include "PasaAltas.h"
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <cfloat>
//#include <armadillo>

gImage::gImage(std::string path) {

	windowSize = 8;

	file = path;
	Magick::Image image2(path);
	image = image2;
	width = (int)image.columns();
	height = (int)image.rows();
	std::cout << "Height " << height << std::endl;
	pixels = image.getPixels(0, 0, width, height);

	imageGradientX.resize(width);
	imageGradientY.resize(width);
	for (int i = 0; i < width; i++) {
		imageGradientX[i].resize(height);
		imageGradientY[i].resize(height);
	}

	sobel();
}

Magick::ColorRGB gImage::getColor(int x, int y) {
	Magick::Color color;
	unsigned offset = image.channels() * (width * x + y);
//	color = (pixels[offset +0].ToInt16, pixels[offset + 1].ToInt16, pixels[offset + 3].ToInt16);

	Magick::ColorRGB rgb(color);
	return rgb;
}

int gImage::getIntensity(int x, int y) {
	double luma = 0;

	//Magick::ColorRGB rgb = getColor(x, y);

	Magick::Color color;
	unsigned offset = image.channels() * (width * x + y);
//	color = (pixels[offset + 0].ToInt16, pixels[offset + 1].ToInt16, pixels[offset + 3].ToInt16);

	//color = pixels[width * y + x];

	Magick::ColorRGB rgb(color);

	luma = (rgb.red() * 256) * 0.2126 +
		(rgb.green() * 256) * 0.7152 +
		(rgb.blue() * 256) * 0.0722;

	return (int)luma;
}


void gImage::sobel() {
	int sobelHorizontal = 0;
	int sobelVertical = 0;

	for (int y = 1; y < height - 2; y++) {

		for (int x = 1; x < width - 2; x++) {

			// Optimized Sobel operation
			sobelHorizontal = getIntensity(x + 1, y - 1) + getIntensity(x + 1, y + 1)
				- getIntensity(x - 1, y - 1) - getIntensity(x - 1, y + 1)
				+ 2 * getIntensity(x + 1, y) - 2 * getIntensity(x - 1, y);

			sobelVertical = getIntensity(x + 1, y + 1) + getIntensity(x - 1, y + 1)
				- getIntensity(x + 1, y - 1) - getIntensity(x - 1, y - 1)
				+ 2 * getIntensity(x, y + 1) - 2 * getIntensity(x - 1, y - 1);

			//std::cout << sobelHorizontal << " ";
			imageGradientX[x][y] = sobelHorizontal;
			imageGradientY[x][y] = sobelVertical;
		}
	}

}



void gImage::sync() {
	image.syncPixels();
}

bool gImage::save(std::string path) {
	bool success = true;
	sync();
	image.write(path);

	return success;
}

int gImage::getWidth() {
	return width;
}

int gImage::getHeight() {
	return height;
}