#pragma once
#include <iostream>
#include <C:\openCV3\opencv\MyBuild\install\include\opencv2\opencv.hpp>
#include <C:\openCV3\opencv\MyBuild\install\include\opencv\highgui.h>
#include "VFunctions.h"

using namespace cv;
using namespace std;


class TrainingSamples
{
public:

	int MaxNumberOfCorners;
	int MinNumberOfCorners;
	int MinSize;
	int MaxSize;
	double MaxPerimeter;
	double MinRoundness;
	double MaxRoundness;
	//CVFunctions Funt;
	//CVFunctions Funtions;
	TrainingSamples();
	~TrainingSamples();

	void ExtractInfoFromImage(Mat image);
	void GetMaxMinCornerValues(double value);
	void GetMaxMinRoundnessValues(double value);
	void GetMaxMinSizeValues(double value);


	void Train(Mat image);
};

