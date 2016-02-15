

#include <C:\openCV3\opencv\MyBuild\install\include\opencv2\opencv.hpp>
#include <C:\openCV3\opencv\MyBuild\install\include\opencv\highgui.h>
#include "VFunctions.h"
using namespace cv;



int main() {
	Mat image, edges, ThImage100, ThImage50;          //Create Matrix to store image
	VideoCapture cap;          //initialize capture
	CVFunctions func = CVFunctions();
	int binaryTH1 = 100;

	cap.open(0);
	namedWindow("window", 1);          //create window to show image

	while (1) {

		image = func.TakeVideoFrame(cap);
		cvtColor(image, edges, CV_BGR2GRAY);  // Change to gray
		GaussianBlur(edges, edges, Size(7, 7), 1.5, 1.5);   // blur (filter_dim, intensity1?,intensity2?)
															//Canny(edges, edges, 0, 30, 3);


		threshold(edges, ThImage100, 100, 255, THRESH_BINARY);
		threshold(edges, ThImage50, 70, 255, THRESH_BINARY);
		imshow("TH100", ThImage100);
		imshow("TH50", ThImage50);



		//cap >> image;          //copy webcam stream to image
		imshow("window", image);          //print image to screen
		waitKey(33);          //delay 33ms
	}
	return 0;
}