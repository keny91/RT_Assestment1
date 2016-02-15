#pragma once
#include <C:\openCV3\opencv\MyBuild\install\include\opencv2\opencv.hpp>
#include <C:\openCV3\opencv\MyBuild\install\include\opencv\highgui.h>
#include <string>
#include <iostream>
#include <cmath>
#include "VFunctions.h"

using namespace std;
using namespace cv;


class FigureShape
{
public:

	string ColorLabel;
	string ColorValue;
	int NCorners;
	

	// Constructor
	FigureShape(string ColorLa, string ColorValue, int NCorners);
	FigureShape();
	~FigureShape();



	void LabelUnknownFigure(Mat image);


};

