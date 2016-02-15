

#include <C:\openCV3\opencv\MyBuild\install\include\opencv2\opencv.hpp>
#include <C:\openCV3\opencv\MyBuild\install\include\opencv\highgui.h>
#include "VFunctions.h"
#include "FigureShape.h"
using namespace cv;



int main() {
	Mat image, grayImg , ThImage100, ThImage50;          //Create Matrix to store image
	VideoCapture cap;          //initialize capture
	CVFunctions func = CVFunctions();
	int binaryTH1 = 100;
	int binaryTH2 = 50;

	cap.open(0);
	namedWindow("window", 1);          //create window to show image


	// do forever
	while (1) {

		image = func.TakeVideoFrame(cap);
		cvtColor(image, grayImg, CV_BGR2GRAY);  // Change to grayScale



		//thresholded images
		ThImage100 = func.SegmentationByTH(grayImg, binaryTH1);
		ThImage50 = func.SegmentationByTH(grayImg, binaryTH2);
		imshow("TH100", ThImage100);
		imshow("TH50", ThImage50);



		//cap >> image;          //copy webcam stream to image
		imshow("window", image);          //print image to screen
		waitKey(33);          //delay 33ms
	}
	return 0;
}