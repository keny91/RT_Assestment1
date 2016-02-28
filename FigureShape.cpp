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


double FigureShape::FindRoundness(double areas, double perimeters) {
	double Round;
	Round = ((perimeters ^ 2) / areas);
	 return roundness
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

void FigureShape::FigureShape::SetContour(vector<Point>  contour){
	contour = contour;
}