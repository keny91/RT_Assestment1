#pragma once
#include <C:\openCV3\opencv\MyBuild\install\include\opencv2\opencv.hpp>
#include <C:\openCV3\opencv\MyBuild\install\include\opencv\highgui.h>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;
using namespace cv;

class CVFunctions
{
public:
	CVFunctions();
	~CVFunctions();


	Mat SegmentationByTH(Mat image);
	Mat TakeVideoFrame(VideoCapture source);

};

