

#include <C:\openCV3\opencv\MyBuild\install\include\opencv2\opencv.hpp>
#include <C:\openCV3\opencv\MyBuild\install\include\opencv\highgui.h>
#include "VFunctions.h"
using namespace cv;



int main() {
	Mat image, ThImage100, ThImage50;          //Create Matrix to store image
	VideoCapture cap;          //initialize capture
	CVFunctions func = CVFunctions();
	int binaryTH1 = 100;
	int binaryTH1 = 50;

	cap.open(0);
	namedWindow("window", 1);          //create window to show image

	while (1) {

		image = func.TakeVideoFrame(cap);
		
		//threshold(edges, ThImage50, 70, 255, THRESH_BINARY);
		ThImage100 = func.SegmentationByTH(image, binaryTH1);
		imshow("TH100", ThImage100);
		imshow("TH50", ThImage50);



		//cap >> image;          //copy webcam stream to image
		imshow("window", image);          //print image to screen
		waitKey(33);          //delay 33ms
	}
	return 0;
}