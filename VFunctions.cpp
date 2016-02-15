#include "VFunctions.h"
#include <iostream>
#include <C:\openCV3\opencv\MyBuild\install\include\opencv2\opencv.hpp>
#include <C:\openCV3\opencv\MyBuild\install\include\opencv\highgui.h>

using namespace cv;
using namespace std;

CVFunctions::CVFunctions()
{
}


CVFunctions::~CVFunctions()
{
}


Mat CVFunctions::SegmentationByTH(Mat image, int TH) {

	Mat edges;
	cvtColor(image, edges, CV_BGR2GRAY);  // Change to gray
	GaussianBlur(edges, edges, Size(7, 7), 1.5, 1.5);   // blur (filter_dim, intensity1?,intensity2?)
	threshold(edges, edges, TH, 255, THRESH_BINARY);
	return image;
}


Mat CVFunctions::TakeVideoFrame(VideoCapture source) {
	Mat image;
	if (!source.isOpened()) {
		cout << "Error, no source found. \n";
		return image;
	}
	else {
		source >> image;
		return image;
	}

}