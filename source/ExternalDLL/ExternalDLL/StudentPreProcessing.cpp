#include "StudentPreProcessing.h"


IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	IntensityImageStudent i_mage(image.getWidth(), image.getHeight);
	for (int i = 0; i < image.getWidth() * image.getHeight(); i++) {
		i_mage.setPixel(i, image.getPixel(i).r * 0.3 + image.getPixel(i).g * 0.59 + image.getPixel(i).b * 0.11);
	}
	return &i_mage;
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