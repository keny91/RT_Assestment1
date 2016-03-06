#pragma once
#include <C:\openCV3\opencv\MyBuild\install\include\opencv2\opencv.hpp>
#include <C:\openCV3\opencv\MyBuild\install\include\opencv\highgui.h>
#include <string>
#include <iostream>
#include <cmath>
#include "TrainingSamples.h"
#include "FigureShape.h"
#include <string.h>

//using namespace std;
using namespace cv;


class CVFunctions
{
public:
	CVFunctions();
	~CVFunctions();


	Mat SegmentationByTH(Mat image, int TH);
	Mat TakeVideoFrame(VideoCapture source);
	Mat* SegmentObjects(Mat Image);
	Mat ClosingHollowFigures(Mat Image);

	Mat FilterBrightPaper(Mat Image, int GreyTH, Mat BWOutputImage);
	Mat ClosingMorph(Mat Image, int radious);
	Mat OpeningMorph(Mat Image, int radious);
	Mat GradientMorph(Mat Image, int radious);

	double CalculateRoundness(double perimeter, double contourSize);
	double IntervalEvaluation(double max, double min, double point, double ValorationTH);
	//XXX GetNumberOfCorners(contour);
	void FindHarrisCorners(Mat c);
	void RunTest();
};

