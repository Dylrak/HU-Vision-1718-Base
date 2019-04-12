#include "IntensityImageStudent.h"

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
	image_shell = NULL;
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()) {
	image_shell = std::make_unique<uint8_t[]>(getWidth() * getHeight()); //Create new image shell array with size of 'other'
	for (int i = 0; i < getWidth() * getHeight(); i++) {
		setPixel(i, other.getPixel(i)); //Get each pixel from other and set it into the new image shell
	}
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height) {
	image_shell = std::make_unique<uint8_t[]>(getWidth() * getHeight());
}

void IntensityImageStudent::set(const int width, const int height) {
	IntensityImage::set(width, height);
	image_shell = std::make_unique<uint8_t[]>(getWidth() * getHeight());
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	IntensityImage::set(other.getWidth(), other.getHeight());
	image_shell = std::make_unique<uint8_t[]>(getWidth() * getHeight());
	for (int i = 0; i < getWidth() * getHeight(); i++) {
		setPixel(i, other.getPixel(i)); //Get each pixel from other and set it into the new image shell
	}
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	image_shell[x * y] = pixel;
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	image_shell[i] = pixel;
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	return image_shell[x * y];
}

Intensity IntensityImageStudent::getPixel(int i) const {
	return image_shell[i];
}