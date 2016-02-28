#include "FigureShape.h"



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

