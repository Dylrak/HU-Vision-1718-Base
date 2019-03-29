#include "RGBImageStudent.h"

RGBImageStudent::RGBImageStudent() : RGBImage() {
	image_shell = NULL;
}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) : RGBImage(other.getWidth(), other.getHeight()) {
	image_shell = new uint8_t[getWidth() * getHeight() * 3]; //Width * Height * 3 for r, g and b
	for (int i = 0; i < getWidth() * getHeight(); i++) {
		setPixel(i, other.getPixel(i));
	}
}


RGBImageStudent::RGBImageStudent(const int width, const int height) : RGBImage(width, height) {
	image_shell = new uint8_t[width * height * 3]; //Width * Height * 3 for r, g and b
}

RGBImageStudent::~RGBImageStudent() {
	delete[] image_shell;
}

void RGBImageStudent::set(const int width, const int height) {
	RGBImage::set(width, height);
	delete[] image_shell;
	image_shell = new uint8_t[width * height * 3]; //Width * Height * 3 for r, g and b
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	RGBImage::set(other.getWidth(), other.getHeight());
	delete[] image_shell;
	image_shell = new uint8_t[getWidth() * getHeight() * 3]; //Width * Height * 3 for r, g and b
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
	int i = x * y; //Pixel position
	setPixel(i, pixel);
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
	image_shell[i] = pixel.r;
	image_shell[i + 1] = pixel.g;
	image_shell[i + 2] = pixel.b;
}

RGB RGBImageStudent::getPixel(int x, int y) const {
	return getPixel(x * y);
}

RGB RGBImageStudent::getPixel(int i) const {
	return RGB(image_shell[i], image_shell[i + 1], image_shell[i + 2]);
}