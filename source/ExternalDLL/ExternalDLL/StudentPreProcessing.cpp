#include "StudentPreProcessing.h"
#include <algorithm>


IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	IntensityImageStudent * intensity_image = new IntensityImageStudent(image.getWidth(), image.getHeight());
	for (int i = 0; i < image.getWidth() * image.getHeight(); i++) {
		uint8_t r, g, b;
		r = image.getPixel(i).r;
		g = image.getPixel(i).g;
		b = image.getPixel(i).b;
		//Comment/uncomment a line of code to choose color-to-grayscale mode
			//Intensity:
		//intensity_image->setPixel(i, (r + g + b) / 3);
			//Luminance (OpenCV standard):
		//intensity_image->setPixel(i, r * 0.3 + g * 0.59 + b * 0.11);
			//Luma:
		//intensity_image->setPixel(i, r * 0.2126 + g * 0.7152 + b * 0.0722);
			
		uint8_t max = std::max(std::max(r,g), std::max(g, b));
			//Value:
		//intensity_image->setPixel(i, max);
			//Luster:
		uint8_t min = std::min(std::min(r, g), std::min(g, b));
		uint8_t c = 0.5 * (max + min);
		intensity_image->setPixel(i, c);
	}
	return intensity_image;
}

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	return nullptr;
}