#include "FigureShape.h"

#include <C:\openCV3\opencv\MyBuild\install\include\opencv2\opencv.hpp>
#include <C:\openCV3\opencv\MyBuild\install\include\opencv\highgui.h>
#include <string>
#include <iostream>
#include <cmath>
#include "VFunctions.h"
#include <math.h>

using namespace std;
using namespace cv;


FigureShape::FigureShape(string ColorL, string ColorV, int NCorn) {
	/*ColorLabel = ColorL;
	ColorValue = ColorV; 
	NCorners = NCorn;*/

}


FigureShape::FigureShape(vector<Point> Contour)
{
	contour = Contour;
}


FigureShape::FigureShape()
{
}


FigureShape::~FigureShape()
{
}


double FigureShape::FindRoundness(double a, double p) {
	double Round = ((p*p) / a);
	return Round;
}


void FigureShape::LabelUnknownFigure(Mat image) {

	



}

void FigureShape::SetPerimeter(double Value) {
	perimeter = Value;
}


void FigureShape::SetContour(vector<Point> Value) {
	contour = Value;
}

void FigureShape::SetRoundness(double Value) {
	roundness = Value;
}

void FigureShape::SetArea(double Value) {
	area = Value;
}

