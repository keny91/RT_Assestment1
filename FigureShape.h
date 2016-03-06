#pragma once
#include <C:\openCV3\opencv\MyBuild\install\include\opencv2\opencv.hpp>
#include <C:\openCV3\opencv\MyBuild\install\include\opencv\highgui.h>
#include <string>
#include <iostream>
#include <cmath>
#include "VFunctions.h"
#include <math.h>

using namespace std;
using namespace cv;


class FigureShape
{
public:

	//string ColorLabel;
	//string ColorValue;
	int NCorners;
	double CircleValoration, SquareValoration , TriangleValoration;
	vector<Point> contours;

	/*
	int FigureMaxPixelSize;
	int FigureMinPixelSize;
	int FigurPixelSize;
	*/

	vector<Point> contour;
	double area;
	double roundness;
	double perimeter;
	int label;

	// Constructor
	FigureShape(string ColorLa, string ColorValue, int NCorners);
	FigureShape();
	FigureShape(vector<Point> Contour);
	~FigureShape();

	double FindRoundness(double a, double p);
	void SetRoundness(double Value);
	void SetArea(double Value);
	void SetPerimeter(double Value);
	void SetContour(vector<Point> Value);


	void LabelUnknownFigure(Mat image);



};

