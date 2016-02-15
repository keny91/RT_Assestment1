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


Mat CVFunctions::SegmentationByTH(Mat image) {

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