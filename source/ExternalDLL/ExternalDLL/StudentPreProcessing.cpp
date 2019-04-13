#include "StudentPreProcessing.h"
#include <algorithm>

//Intensity:
/*
IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	IntensityImageStudent * intensity_image = new IntensityImageStudent(image.getWidth(), image.getHeight());
	for (int i = 0; i < image.getWidth() * image.getHeight(); i++) {
		uint8_t r, g, b;
		r = image.getPixel(i).r;
		g = image.getPixel(i).g;
		b = image.getPixel(i).b;
		intensity_image->setPixel(i, (r + g + b) / 3);
	}
	return intensity_image;
}
*/
//Luminance (OpenCV standard):

IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	IntensityImageStudent * intensity_image = new IntensityImageStudent(image.getWidth(), image.getHeight());
	for (int i = 0; i < image.getWidth() * image.getHeight(); i++) {
		uint8_t r, g, b;
		r = image.getPixel(i).r;
		g = image.getPixel(i).g;
		b = image.getPixel(i).b;
		intensity_image->setPixel(i, r * 0.3 + g * 0.59 + b * 0.11);
	}
	return intensity_image;
}

//Luma:
/*
IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	IntensityImageStudent * intensity_image = new IntensityImageStudent(image.getWidth(), image.getHeight());
	for (int i = 0; i < image.getWidth() * image.getHeight(); i++) {
		uint8_t r, g, b;
		r = image.getPixel(i).r;
		g = image.getPixel(i).g;
		b = image.getPixel(i).b;
		intensity_image->setPixel(i, r * 0.2126 + g * 0.7152 + b * 0.0722);
	}
	return intensity_image;
}
*/
//Value:
/*
IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	IntensityImageStudent * intensity_image = new IntensityImageStudent(image.getWidth(), image.getHeight());
	for (int i = 0; i < image.getWidth() * image.getHeight(); i++) {
		uint8_t r, g, b;
		r = image.getPixel(i).r;
		g = image.getPixel(i).g;
		b = image.getPixel(i).b;
		uint8_t max = std::max(std::max(r, g), std::max(g, b));
		intensity_image->setPixel(i, max);
	}
	return intensity_image;
}
*/
//Luster:
/*
IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	IntensityImageStudent * intensity_image = new IntensityImageStudent(image.getWidth(), image.getHeight());
	for (int i = 0; i < image.getWidth() * image.getHeight(); i++) {
		uint8_t r, g, b;
		r = image.getPixel(i).r;
		g = image.getPixel(i).g;
		b = image.getPixel(i).b;
		uint8_t max = std::max(std::max(r, g), std::max(g, b));
		uint8_t min = std::min(std::min(r, g), std::min(g, b));
		uint8_t c = 0.5 * (max + min);
		intensity_image->setPixel(i, c);
	}
	return intensity_image;
}
*/

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	return nullptr;
}