#include "IntensityImageStudent.h"

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
	image_shell = NULL;
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()) {
	image_shell = new Intensity[getWidth() * getHeight()]; //Create new image shell array with size of 'other'
	for (int i = 0; i < (getWidth() * getHeight()); i++) {
		setPixel(i, other.getPixel(i)); //Get each pixel from other and set it into the new image shell
	}
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height) {
	image_shell = new Intensity[getWidth() * getHeight()];
}

IntensityImageStudent::~IntensityImageStudent() {
	delete[] image_shell;
}

void IntensityImageStudent::set(const int width, const int height) {
	IntensityImage::set(width, height);
	delete[] image_shell;
	image_shell = new Intensity[getWidth() * getHeight()];
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	IntensityImage::set(other.getWidth(), other.getHeight());
	delete[] image_shell;
	image_shell = new Intensity[getWidth() * getHeight()];
	for (int i = 0; i < (getWidth() * getHeight()); i++) {
		setPixel(i, other.getPixel(i)); //Get each pixel from other and set it into the new image shell
	}
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	setPixel(x * y, pixel);
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	image_shell[i] = pixel;
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	return getPixel(y * getWidth() + x);
}

Intensity IntensityImageStudent::getPixel(int i) const {
	return Intensity(image_shell[i]);
}