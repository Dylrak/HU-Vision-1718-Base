#include "RGBImageStudent.h"

RGBImageStudent::RGBImageStudent() : RGBImage() {
	image_shell = NULL;
}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) : RGBImage(other.getWidth(), other.getHeight()) {
	image_shell = std::make_unique<uint32_t[]>(getWidth() * getHeight()); //Create new image shell array with size of 'other'
	for (int i = 0; i < getWidth() * getHeight(); i++) {
		setPixel(i, other.getPixel(i)); //Get each pixel from other and set it into the new image shell
	}
}

RGBImageStudent::RGBImageStudent(const int width, const int height) : RGBImage(width, height) {
	image_shell = std::make_unique<uint32_t[]>(getWidth() * getHeight());
}

RGBImageStudent::~RGBImageStudent() {
}

//Resize or create a new pixel storage, deleting the old storage in the process (if it exists)
void RGBImageStudent::set(const int width, const int height) {
	RGBImage::set(width, height);
	image_shell = std::make_unique<uint32_t[]>(getWidth() * getHeight());
}

//Resize or create a new pixel storage and copy the object, deleting the old storage in the process (if it exists)
void RGBImageStudent::set(const RGBImageStudent &other) {
	RGBImage::set(other.getWidth(), other.getHeight());
	image_shell = std::make_unique<uint32_t[]>(getWidth() * getHeight());
	for (int i = 0; i < getWidth() * getHeight(); i++) {
		setPixel(i, other.getPixel(i)); //Get each pixel from other and set it into the new image shell
	}
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) { //Function assumes correct x- and y-values, no out-of-bounds check 
	image_shell[x * y] = pixel.r << 16 + pixel.g << 8 + pixel.b; // (empty)(byte r)(byte g)(byte b)
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
	image_shell[i] = pixel.r << 16 + pixel.g << 8 + pixel.b; // (empty)(byte r)(byte g)(byte b)
}

RGB RGBImageStudent::getPixel(int x, int y) const {
	return getPixel(y * getWidth() + x); //Call getPixel(int i)
}

RGB RGBImageStudent::getPixel(int i) const {
	return RGB(image_shell[i] >> 16, image_shell[i] >> 8 && 0b11111111, image_shell[i] && 0b11111111); //Bitshift to the right, then AND with last 8 bits to mask away the other values
}