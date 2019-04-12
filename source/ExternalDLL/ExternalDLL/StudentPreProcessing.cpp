#include "StudentPreProcessing.h"
#include <algorithm>


IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	IntensityImageStudent * intensity_image = new IntensityImageStudent(image.getWidth(), image.getHeight());
	for (int i = 0; i < image.getWidth() * image.getHeight(); i++) {
		int r, g, b;
		r = int(image.getPixel(i).r);
		g = int(image.getPixel(i).g);
		b = int(image.getPixel(i).b);
		int max = std::max(std::max(r,g), std::max(g, b));
		int min = std::max(std::max(r, g), std::max(g, b));
		int c = 0.5 * ((uint64_t)max + (uint64_t)min);
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