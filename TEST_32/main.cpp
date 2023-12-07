#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat src,dst,gray,two;
void callback(int,void*);
int value=174;
int main()
{
	src=imread("xray.jpg",IMREAD_UNCHANGED);
	dst=Mat(src.size(),src.type());
	dst=Scalar(255,255,255);
	imshow("src",src);
	cvtColor(src,gray,COLOR_RGB2GRAY);
	namedWindow("dst",WINDOW_AUTOSIZE);
	createTrackbar("bar","dst",&value,255,callback);
	
	waitKey(0);
	return 0;
}

void callback(int,void*)
{
	Canny(gray,two,value,value*2,3);
	dst=Scalar(255,255,255);

	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	findContours(two,contours,hierarchy,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);
	vector<vector<Point>> hull( contours.size() );
	for(int i=0;i<contours.size();i++)
	{
		convexHull(Mat(contours[i]),hull[i]);
	}

	for(int i=0;i<hull.size();i++)
	{
		drawContours(dst,hull,i,Scalar(0,0,255),1,LINE_AA);
	}
	imshow("dst",dst);
}
	

	
