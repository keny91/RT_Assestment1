#include "VFunctions.h"

#include <C:\openCV3\opencv\MyBuild\install\include\opencv2\opencv.hpp>
#include <C:\openCV3\opencv\MyBuild\install\include\opencv\highgui.h>
#include <string>
#include <iostream>
#include <cmath>
#include "TrainingSamples.h"
#include "FigureShape.h"
#include <string.h>


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
Mat CVFunctions::ClosingHollowFigures(Mat Image) {


	return Image;
}



Mat CVFunctions::FilterBrightPaper(Mat Image, int GreyTH, Mat BWOutputImage) {


	for (int i = 0; i < Image.cols; i++) {
		for (int j = 0; j < Image.rows; j++) {
			if (Image.at<uchar>(Point(i, j))> GreyTH)
				BWOutputImage.at<int>(Point(i, j)) = 0;
		}
	}
	return BWOutputImage;
}



/*
Morphology Operations
*/

Mat CVFunctions::ClosingMorph(Mat Image, int radious) {
	Mat kernel, eroded, dilatated;
	cv::Mat element(radious, radious, CV_8U, cv::Scalar(1));
	cv::dilate(Image, dilatated, element);
	cv::erode(dilatated, eroded, element);
	return eroded;

}

Mat CVFunctions::OpeningMorph(Mat Image, int radious) {
	Mat kernel, eroded, dilatated;
	cv::Mat element(radious, radious, CV_8U, cv::Scalar(1));
	cv::erode(Image, eroded, element);
	cv::dilate(eroded, dilatated, element);

	return dilatated;

}




Mat CVFunctions::GradientMorph(Mat Image, int radious) {
	Mat gradient, eroded, dilatated;
	cv::Mat element(radious, radious, CV_8U, cv::Scalar(1));
	cv::erode(Image, eroded, element);
	cv::dilate(Image, dilatated, element);
	gradient = dilatated - eroded;
	
	return gradient;

}


double CVFunctions::CalculateRoundness(double perimeter, double contourSize) {
	//double roundness = 
	return (perimeter * perimeter) / contourSize;
}

double CVFunctions::IntervalEvaluation(double max, double min, double point, double ValorationTH) {
	double Interval = (max - min) / 2;
	double middlePoint = Interval + min;
	double distance = abs(point - middlePoint);
	double valoration;
	if (distance <= Interval) {
		valoration = 1 - distance / Interval;
	}
	else
		valoration = 0;

	return valoration*ValorationTH;


}




void CVFunctions::FindHarrisCorners(Mat src)
{
	//Mat src, src_gray;
	int thresh = 200;
	int max_thresh = 255;

	char* source_window = "Source image";
	char* corners_window = "Corners detected";


	Mat dst, dst_norm, dst_norm_scaled;
	dst = Mat::zeros(src.size(), CV_32FC1);

	/// Detector parameters
	int blockSize = 2;
	int apertureSize = 3;
	double k = 0.04;

	/// Detecting corners
	cornerHarris(src, dst, blockSize, apertureSize, k, BORDER_DEFAULT);

	/// Normalizing
	normalize(dst, dst_norm, 0, 255, NORM_MINMAX, CV_32FC1, Mat());
	convertScaleAbs(dst_norm, dst_norm_scaled);

	/// Drawing a circle around corners
	for (int j = 0; j < dst_norm.rows; j++)
	{
		for (int i = 0; i < dst_norm.cols; i++)
		{
			if ((int)dst_norm.at<float>(j, i) > thresh)
			{
				circle(dst_norm_scaled, Point(i, j), 5, Scalar(0), 2, 8, 0);
			}
		}
	}
	/// Showing the result
	namedWindow(corners_window, CV_WINDOW_AUTOSIZE);
	imshow(corners_window, dst_norm_scaled);
}


void CVFunctions::RunTest() {


	Mat image, grayImg, BWImage, BgSustImg, ThImage100, ThImage50, BWImage2, BG, grayImgBG, CannyImage;          //Create Matrix to store image
	Ptr<BackgroundSubtractorMOG2> bgSust;
	VideoCapture cap;          //initialize capture
	CVFunctions func = CVFunctions();
	int binaryTH1 = 100;
	int binaryTH2 = 50;
	FigureShape *TheFigures = new FigureShape();
	FigureShape TheFigure = FigureShape();
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;
	RNG rng(12345);
	// Find and identify contours
	double contourSize, perimeter, roundness;
	double mincontourSize = 100;

	cout << "Do you know which confiruration are you going to use? \n \n";
	cout << "A)  Using a plain surface\n  The camera must be orinted orthogonaly to the surface. No further set up is required, just wait until the camera is running before you instert any of the sample sheets \n \n";
	cout << "B)  You will hold the paper yourself. \n  You require to maintain occluded the camera until the camera has been initialized. \n NOTE: try to hold the paper carefully from a single side if possible.\n\n\n";



	cap.open(0);
	BG = func.TakeVideoFrame(cap);

	// START TRAINING 
	TrainingSamples Triangles, Squares, Circles = TrainingSamples();
	Mat TrainTriangles, TrainSquares, TrainCircles;

	//Read training images
	TrainTriangles = imread(".\\Triangles.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	resize(TrainTriangles, TrainTriangles, BG.size(), 0.2, 0.2);
	TrainSquares = imread(".\\Squares.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	resize(TrainSquares, TrainSquares, BG.size(), 0.2, 0.2);
	TrainCircles = imread("C:\\Users\\keny\\Desktop\\Circles.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	resize(TrainCircles, TrainCircles, BG.size(), 0.2, 0.2);
	//imshow("Triangles", TrainSquares);

	Triangles.Train(TrainTriangles);
	Squares.Train(TrainSquares);
	Circles.Train(TrainCircles);



	bgSust = createBackgroundSubtractorMOG2();
	cvtColor(BG, grayImgBG, CV_BGR2GRAY);

	while (1) {
		waitKey(30);
		image = func.TakeVideoFrame(cap);
		//image = image - BG;
		//bgSust->apply(image, BgSustImg);
		bgSust->apply(image, grayImg);
		image = func.TakeVideoFrame(cap);
		cvtColor(image, grayImg, CV_BGR2GRAY);
		grayImg = grayImg - grayImgBG;

		//imshow("Capture", image);

		vector<vector<Point> > contours;
		vector<Vec4i> hierarchy;
		Mat contourImage = Mat::zeros(grayImg.size(), CV_8UC3);
		Canny(grayImg, CannyImage, 100, 200, 3);
		//imshow("CannyEdges", CannyImage);

		findContours(CannyImage, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_NONE, Point(0, 0));
		vector<Point>contours_approx;

		for (unsigned int i = 0; i < contours.size(); i++) {
			approxPolyDP(Mat(contours[i]), contours_approx, arcLength(Mat(contours[i]), true) * 0.01, true);
			if (hierarchy[i][3] >= 0) {   //has parent, inner (hole) contour of a closed edge (looks good)
				contourSize = contourArea(contours[i]);
				perimeter = arcLength(contours[i], true);
				if (contourSize > mincontourSize) {
					roundness = func.CalculateRoundness(perimeter, contourSize);
					//roundness = (perimeter * perimeter) / contourSize;
					TheFigure.TriangleValoration = func.IntervalEvaluation(Triangles.MaxRoundness, Triangles.MinRoundness, roundness, 1);
					TheFigure.CircleValoration = func.IntervalEvaluation(Circles.MaxRoundness, Circles.MinRoundness, roundness, 1);
					TheFigure.SquareValoration = func.IntervalEvaluation(Squares.MaxRoundness, Squares.MinRoundness, roundness, 1);
					if (TheFigure.SquareValoration > TheFigure.CircleValoration && TheFigure.SquareValoration > TheFigure.TriangleValoration) {

						drawContours(contourImage, contours, i, Scalar(255, 0, 0), 1, 8);
						//cout << roundness << "\n";
					}
					else if (TheFigure.CircleValoration > TheFigure.SquareValoration && TheFigure.CircleValoration > TheFigure.TriangleValoration) {
						drawContours(contourImage, contours, i, Scalar(0, 0, 255), 1, 8);
					}

					else
						drawContours(contourImage, contours, i, Scalar(0, 255, 0), 1, 8);
					//drawContours(contourImage, contours_approx, -1, Scalar(0, 255, 0), 1, 8);
				}


			}
		}


		double pointPolygonTest(InputArray contour, Point2f pt, bool measureDist);
		imshow("THafterSegme", contourImage);








	}
}