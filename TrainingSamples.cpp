#include "TrainingSamples.h"
#include <C:\openCV3\opencv\MyBuild\install\include\opencv2\opencv.hpp>
#include <C:\openCV3\opencv\MyBuild\install\include\opencv\highgui.h>
#include "VFunctions.h"

using namespace cv;
using namespace std;


//
int MaxNumberOfCorners;
int MinNumberOfCorners;
int MinSize;
int MaxSize;
double MaxPerimeter;
double MinRoundness;
double MaxRoundness;


TrainingSamples::TrainingSamples()
{
	MinRoundness = 0;
	MaxRoundness = 0;
	MaxNumberOfCorners = 0;;
	MinNumberOfCorners =0;
	MinSize= 0;
	MaxSize=0;
//	CVFunctions Funtions= CVFunctions();
}


TrainingSamples::~TrainingSamples()
{
}

void TrainingSamples::ExtractInfoFromImage(Mat image) {


}

void TrainingSamples::GetMaxMinCornerValues(double value){

	if (MinNumberOfCorners == 0 || MinNumberOfCorners > value)
		MinNumberOfCorners = value;
	if (MaxNumberOfCorners == 0 || MaxNumberOfCorners < value)
		MaxNumberOfCorners = value;
}


void TrainingSamples::GetMaxMinRoundnessValues(double value) {
	if (MinRoundness == 0 || MinRoundness > value)
		MinRoundness = value;
	if (MaxRoundness == 0 || MaxRoundness < value)
		MaxRoundness = value;
}

void TrainingSamples::GetMaxMinSizeValues(double value) {
	if (MinSize == 0 || MinSize > value)
		MinSize = value;
	if (MaxSize == 0 || MaxSize < value)
		MaxSize = value;

}

void TrainingSamples::Train(Mat image) {

	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;
	Mat CannyImage;
	Mat contourImage = Mat::zeros(image.size(), CV_8UC3);
	double contourSize, perimeter, roundness;
	int max = 60300;
	int min = 50;
	CVFunctions Funt = CVFunctions();

	Canny(image, CannyImage, 100, 200, 3);
	findContours(CannyImage, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_NONE, Point(0, 0));

	for (unsigned int i = 0; i < contours.size(); i++) {
		if (hierarchy[i][3] >= 0) {
			contourSize = contourArea(contours[i]);
			perimeter = arcLength(contours[i], true);
			roundness = Funt.CalculateRoundness(perimeter, contourSize);

			if (contourSize<max && contourSize>min) {

				GetMaxMinSizeValues(contourSize);
				GetMaxMinRoundnessValues(roundness);
				//GetMaxMinCornerValues(double value);
				drawContours(contourImage, contours, i, Scalar(255, 0, 0), 1, 8);

			}
			


			//ret = matchShapes(cnt1, cnt2, 1, 0.0); //TOO SLOW FOR RT


			//imshow("Contours", contourImage);
		}
	}
	Mat dst = Mat::zeros(image.size(), CV_8UC3);
	//cornerHarris(contourImage, dst, 2, 3, 0.04);
	////Funtions.FindHarrisCorners(contourImage);
	//dilate(dst, dst,3);
	//imshow("Contours", dst);
}