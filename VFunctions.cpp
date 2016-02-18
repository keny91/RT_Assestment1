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

/*
	SegmentationByTH: takes and image and applies a segmentation th to create a Binary Image 
*/
Mat CVFunctions::SegmentationByTH(Mat image, int TH) {

	Mat edges;
	GaussianBlur(image, edges, Size(7, 7), 1.5, 1.5);   // blur (filter_dim, intensity1?,intensity2?)
	threshold(edges, edges, TH, 255, THRESH_BINARY);  // with CV_THRESH_BINARY_INV  we get the inverted sample
	return edges;
}

/*
TakeVideoFrame: takes a frame from a video source
*/
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


/*
SegmentObjects: Separate connected elements into different images
*/
Mat* CVFunctions::SegmentObjects(Mat Image) {

	return &Image;
}


/*
ClosingHollowFigures: Separate connected elements into different images
*/
Mat ClosingHollowFigures(Mat Image) {


	return Image;
}