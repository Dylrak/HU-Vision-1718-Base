/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#include <iostream> //std::cout
#include <fstream> //Testset image access
#include "ImageIO.h" //Image load and save functionality
#include "HereBeDragons.h"
#include "ImageFactory.h"
#include "DLLExecution.h"

void drawFeatureDebugImage(IntensityImage &image, FeatureMap &features);
int executeSteps(DLLExecution * executor);

int main(int argc, char * argv[]) {

	ImageFactory::setImplementation(ImageFactory::DEFAULT);
	//ImageFactory::setImplementation(ImageFactory::STUDENT);

	ImageIO::debugFolder = "C:\\Users\\<USERNAME>\\Documents\\Vision\\FaceMinMin";
	ImageIO::isInDebugMode = true; //If set to false the ImageIO class will skip any image save function calls

	std::string testset_path = "C:\\Users\\<USERNAME>\\Documents\\Vision\\testsets\\Set A\\TestSet Images\\";

	// Uncomment the code below for testing the time for RGBImage shell:

	/*
	RGBImage * input = ImageFactory::newRGBImage();
	std::cout << "Loading first image:\n";
	if (!ImageIO::loadImage(testset_path + "test (1).png", *input)) {
		std::cout << "Image could not be loaded!" << std::endl;
		system("pause");
		return 0;
	}
	RGBImage * input2 = ImageFactory::newRGBImage();
	std::cout << "Loading second image:\n";
	if (!ImageIO::loadImage(testset_path + "test (2).png", *input2)) {
		std::cout << "Image could not be loaded!" << std::endl;
		system("pause");
		return 0;
	}
	RGBImage * input3 = ImageFactory::newRGBImage();
	std::cout << "Loading third image:\n";
	if (!ImageIO::loadImage(testset_path + "test (3).png", *input3)) {
		std::cout << "Image could not be loaded!" << std::endl;
		system("pause");
		return 0;
	}

	ImageIO::saveRGBImage(*input, ImageIO::getDebugFileName("debug.png"));

	DLLExecution * executor = new DLLExecution(input);


	if (executeSteps(executor)) {
		std::cout << "Face recognition successful!" << std::endl;
		std::cout << "Facial parameters: " << std::endl;
		for (int i = 0; i < 16; i++) {
			std::cout << (i+1) << ": " << executor->facialParameters[i] << std::endl;
		}
	}

	delete executor;
	*/

	// Uncomment the code below for testing the performance of preprocessing techniques:

	/*
	const static int testset_size = 13; //This is the hard-coded amount of images in the test set.
	const static int step_amount = 20;
	const std::string image_name = "test (";

	int recognition_score = 0;

	RGBImage * input = ImageFactory::newRGBImage();

	for (int i = 0; i < testset_size; i++)
	{
		try {
			std::cout << "Current image suffix: " << std::to_string(i) << std::endl;
			if (!ImageIO::loadImage(testset_path + image_name + std::to_string(i) + ").png", *input)) {
				std::cout << "Image: " << testset_path << image_name << std::to_string(i) << ").png" << "could not be loaded!" << std::endl;
				system("pause");
				return 0;
			}
			DLLExecution * executor = new DLLExecution(input);

			recognition_score += executeSteps(executor);

			delete executor;
		}
		catch (std::exception e)
		{
			//Do nothing; go to next image. Crashing gives a recognition score of zero.
		}
	}
	//Calculate average percentage of how far the entire test set managed to complete the recognition steps.
	std::cout << "Average completion percentage: " << recognition_score / (float)(step_amount * testset_size) * 100 << '%' << std::endl;
	*/


	// Don't comment out code from here
	system("pause");
	return 1;
}

int executeSteps(DLLExecution * executor) {

	//Execute the four Pre-processing steps
	if (!executor->executePreProcessingStep1(true)) {
		std::cout << "Pre-processing step 1 failed!" << std::endl;
		return 1;
	}

	if (!executor->executePreProcessingStep2(false)) {
		std::cout << "Pre-processing step 2 failed!" << std::endl;
		return 2;
	}
	ImageIO::saveIntensityImage(*executor->resultPreProcessingStep2, ImageIO::getDebugFileName("Pre-processing-2.png"));

	if (!executor->executePreProcessingStep3(false)) {
		std::cout << "Pre-processing step 3 failed!" << std::endl;
		return 3;
	}
	ImageIO::saveIntensityImage(*executor->resultPreProcessingStep3, ImageIO::getDebugFileName("Pre-processing-3.png"));

	if (!executor->executePreProcessingStep4(false)) {
		std::cout << "Pre-processing step 4 failed!" << std::endl;
		return 4;
	}
	ImageIO::saveIntensityImage(*executor->resultPreProcessingStep4, ImageIO::getDebugFileName("Pre-processing-4.png"));



	//Execute the localization steps
	if (!executor->prepareLocalization()) {
		std::cout << "Localization preparation failed!" << std::endl;
		return 5;
	}

	if (!executor->executeLocalizationStep1(false)) {
		std::cout << "Localization step 1 failed!" << std::endl;
		return 6;
	}

	if (!executor->executeLocalizationStep2(false)) {
		std::cout << "Localization step 2 failed!" << std::endl;
		return 7;
	}

	if (!executor->executeLocalizationStep3(false)) {
		std::cout << "Localization step 3 failed!" << std::endl;
		return 8;
	}

	if (!executor->executeLocalizationStep4(false)) {
		std::cout << "Localization step 4 failed!" << std::endl;
		return 9;
	}

	if (!executor->executeLocalizationStep5(false)) {
		std::cout << "Localization step 5 failed!" << std::endl;
		return 10;
	}



	//Execute the extraction steps
	if (!executor->prepareExtraction()) {
		std::cout << "Extraction preparation failed!" << std::endl;
		return 11;
	}

	if (!executor->executeExtractionStep1(false)) {
		std::cout << "Extraction step 1 failed!" << std::endl;
		return 12;
	}

	if (!executor->executeExtractionStep2(false)) {
		std::cout << "Extraction step 2 failed!" << std::endl;
		return 13;
	}

	if (!executor->executeExtractionStep3(false)) {
		std::cout << "Extraction step 3 failed!" << std::endl;
		return 14;
	}


	//Post processing and representation
	if (!executor->executePostProcessing()) {
		std::cout << "Post-processing failed!" << std::endl;
		return 15;
	}

	drawFeatureDebugImage(*executor->resultPreProcessingStep1, executor->featuresScaled);

	if (!executor->executeRepresentation()) {
		std::cout << "Representation failed!" << std::endl;
		return 16;
	}
	return 20;
}

void drawFeatureDebugImage(IntensityImage &image, FeatureMap &features) {
	RGB colorRed(244, 67, 54);
	RGBImage * debug = ImageFactory::newRGBImage(image.getWidth(), image.getHeight());
	ImageIO::intensityToRGB(image, *debug);

	//Nose
	Point2D<double> noseLeft = features.getFeature(Feature::FEATURE_NOSE_END_LEFT)[0];
	Point2D<double> noseRight = features.getFeature(Feature::FEATURE_NOSE_END_RIGHT)[0];
	Point2D<double> nostrilLeft = features.getFeature(Feature::FEATURE_NOSTRIL_LEFT)[0];
	Point2D<double> nostrilRight = features.getFeature(Feature::FEATURE_NOSTRIL_RIGHT)[0];
	Point2D<double> noseBottom = features.getFeature(Feature::FEATURE_NOSE_BOTTOM)[0];


	//These (weird) methods can be used to draw debug points
	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, noseLeft, colorRed);
	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, noseRight, colorRed);
	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, nostrilLeft, colorRed);
	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, nostrilRight, colorRed);
	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, noseBottom, colorRed);

	//Chin
	std::vector<Point2D<double>> points = features.getFeature(Feature::FEATURE_CHIN_CONTOUR).getPoints();
	for (size_t i = 0; i < points.size(); i++) {
		HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, points[i], colorRed);
	}

	//Eye
	Feature leftEye = features.getFeature(Feature::FEATURE_EYE_LEFT_RECT);
	Feature rightEye = features.getFeature(Feature::FEATURE_EYE_RIGHT_RECT);


	//These (weird) methods can be used to draw debug rects
	HereBeDragons::AsHisTriumphantPrizeProudOfThisPride(*debug, leftEye[0], leftEye[1], colorRed);
	HereBeDragons::AsHisTriumphantPrizeProudOfThisPride(*debug, rightEye[0], rightEye[1], colorRed);


	//Head
	Feature headTop = features.getFeature(Feature::FEATURE_HEAD_TOP);
	Feature headLeftNoseMiddle = features.getFeature(Feature::FEATURE_HEAD_LEFT_NOSE_MIDDLE);
	Feature headLeftNoseBottom = features.getFeature(Feature::FEATURE_HEAD_LEFT_NOSE_BOTTOM);
	Feature headRightNoseMiddle = features.getFeature(Feature::FEATURE_HEAD_RIGHT_NOSE_MIDDLE);
	Feature headRightNoseBottom = features.getFeature(Feature::FEATURE_HEAD_RIGHT_NOSE_BOTTOM);
	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, headTop[0], colorRed);
	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, headLeftNoseMiddle[0], colorRed);
	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, headLeftNoseBottom[0], colorRed);
	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, headRightNoseMiddle[0], colorRed);
	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, headRightNoseBottom[0], colorRed);

	//Mouth
	Point2D<double> mouthTop = features.getFeature(Feature::FEATURE_MOUTH_TOP)[0];
	Point2D<double> mouthBottom = features.getFeature(Feature::FEATURE_MOUTH_BOTTOM)[0];
	Point2D<double> mouthLeft = features.getFeature(Feature::FEATURE_MOUTH_CORNER_LEFT)[0];
	Point2D<double> mouthRight = features.getFeature(Feature::FEATURE_MOUTH_CORNER_RIGHT)[0];

	//This (weird) method can be used to draw a debug line
	HereBeDragons::ButRisingAtThyNameDothPointOutThee(*debug, mouthLeft, mouthRight, colorRed);

	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, mouthTop, colorRed);
	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, mouthBottom, colorRed);
	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, mouthLeft, colorRed);
	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, mouthRight, colorRed);

	ImageIO::saveRGBImage(*debug, ImageIO::getDebugFileName("feature-points-debug.png"));
	delete debug;
}