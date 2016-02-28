

#include <C:\openCV3\opencv\MyBuild\install\include\opencv2\opencv.hpp>
#include <C:\openCV3\opencv\MyBuild\install\include\opencv\highgui.h>
#include <Windows.h>
#include "VFunctions.h"
#include "FigureShape.h"

using namespace cv;
using namespace std;


int main() {
	Mat image, grayImg, BWImage, BgSustImg, ThImage100, ThImage50, BWImage2, BG, grayImgBG, CannyImage;          //Create Matrix to store image
	Ptr<BackgroundSubtractorMOG2> bgSust;
	VideoCapture cap;          //initialize capture
	CVFunctions func = CVFunctions();
	int binaryTH1 = 100;
	int binaryTH2 = 50;

	FigureShape *TheFigures = new FigureShape();

	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;
	RNG rng(12345);


	cap.open(0);
	//Sleep(2000);
	namedWindow("window", 1);          //create window to show image
	BG = func.TakeVideoFrame(cap); // store raw BackGround
	
	bgSust = createBackgroundSubtractorMOG2();
	cvtColor(BG, grayImgBG, CV_BGR2GRAY);
	//cvtColor(image, grayImg, CV_BGR2GRAY);  
	// do forever
	while (1) {
		waitKey(30);
		image = func.TakeVideoFrame(cap);
		//image = image - BG;
		//bgSust->apply(image, BgSustImg);
		bgSust->apply(image, grayImg);
		image = func.TakeVideoFrame(cap);
		cvtColor(image, grayImg, CV_BGR2GRAY);
		grayImg = grayImg - grayImgBG;

		imshow("BGsust", grayImg);

		//ThImage100 = func.SegmentationByTH(grayImg, binaryTH1);
		// = FilterBrightPaper(Mat Image, 100, Mat BWOutputImage)

		vector<vector<Point> > contours;
		vector<Vec4i> hierarchy;
		Mat contourImage = Mat::zeros(grayImg.size(), CV_8UC3);
		Canny(grayImg, CannyImage, 100, 200, 3);
		imshow("CannyEdges", CannyImage);

		

		// Find and identify contours
		double contourSize, perimeter, roundness;
		double mincontourSize = 100;


		//// Find and identify contours
		//double contourSize, perimeter, roundness;
		//double mincontourSize = 100;
		//int index = 0;

		//findContours(CannyImage, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_NONE, Point(0, 0));
		//for (unsigned int i = 0; i<contours.size(); i++) {
		//	if (hierarchy[i][3] >= 0) {   //has parent, inner (hole) contour of a closed edge (looks good)
		//		contourSize = contourArea(contours[i]);
		//		cout << contourSize + '\n';
		//		if (contourSize > mincontourSize) {

		//			perimeter = arcLength(contours[i], true);
		//			TheFigures[index] = FigureShape(contours[i]);

		//			TheFigures[index].SetRoundness(TheFigures[index].FindRoundness(contourSize, perimeter));
		//			TheFigures[index].SetArea(contourSize);
		//			TheFigures[index].SetPerimeter(perimeter);
		//			//TheFigures[index] = NewShape;
		//			drawContours(contourImage, contours, i, Scalar(255, 0, 0), 1, 8);
		//			index++;
		//		}


		//	}
		//}


		findContours(CannyImage, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_NONE, Point(0, 0));
		for (unsigned int i = 0; i<contours.size(); i++){
			if (hierarchy[i][3] >= 0){   //has parent, inner (hole) contour of a closed edge (looks good)
				contourSize = contourArea(contours[i]);
				perimeter = arcLength(contours[i], true);
				if (contourSize > mincontourSize) {
					roundness = (perimeter * perimeter) / contourSize;

					//if()
					drawContours(contourImage, contours, i, Scalar(255, 0, 0), 1, 8);
				}
					

			}
		}
		// This test returns +1 if inside / -1 if outside / 0 if if border
		double pointPolygonTest(InputArray contour, Point2f pt, bool measureDist);

		imshow("THafterSegme", contourImage);

	
		//thresholded images
		//Canny(grayImg, BWImage, 0, 50, 5);  // input, output, , threshold1,  threshold2, apertureSize=3 L2gradient =false
		//BWImage2 =func.FilterBrightPaper(grayImg, 200, BWImage);
		

		//ThImage100 = func.SegmentationByTH(grayImg, binaryTH1);
		//ThImage50 = func.SegmentationByTH(grayImg, binaryTH2);
		/*imshow("TH100", ThImage100);
		imshow("TH50", ThImage50);*/


		// image 
		/*findContours(ThImage100, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
		vector<vector<Point> > contours_poly(contours.size());



		vector<Rect> boundRect(contours.size());
		vector<Point2f>center(contours.size());
		vector<float>radius(contours.size());*/

		//for (int i = 0; i < contours.size(); i++)
		//{
		//	TheFigures[i].SetContour(contours[i]);
		//	cout << " Number of detected Contours" << contours.size();
		//	/*
		//	approxPolyDP(Mat(contours[i]), contours_poly[i], 3, true); 
		//	boundRect[i] = boundingRect(Mat(contours_poly[i]));   // Rectangle
		//	minEnclosingCircle((Mat)contours_poly[i], center[i], radius[i]);   // Circle
		//	*/
		//}


		/// Draw polygonal contour + bonding rects + circles
	/*	Mat drawing = Mat::zeros(ThImage100.size(), CV_8UC3);
		for (int i = 0; i< contours.size(); i++)
		{
			Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
			drawContours(drawing, contours_poly, i, color, 1, 8, vector<Vec4i>(), 0, Point());
			rectangle(drawing, boundRect[i].tl(), boundRect[i].br(), color, 2, 8, 0);
			circle(drawing, center[i], (int)radius[i], color, 2, 8, 0);
		}
*/
		/// Show in a window
		//namedWindow("Contours", CV_WINDOW_AUTOSIZE);
		//imshow("Contours", drawing);

		//////////////////////////////

		//cap >> image;          //copy webcam stream to image
		imshow("window", image);          //print image to screen
		waitKey(30);          //delay 33ms
	}
	return 0;
}