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
	src=imread("xray.jpg",IMREAD_UNCHANGED);
	dst=Scalar(255,255,255);

	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	findContours(two,contours,hierarchy,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);
	vector<vector<Point>> hull( contours.size() );
	vector<Rect> rect( contours.size() );
	vector<RotatedRect> rect_( contours.size() );
	vector<RotatedRect> ellipsee( contours.size() );
	vector<Point2f> center( contours.size() );
	vector<float> radius( contours.size() );
	for(int i=0;i<hull.size();i++)
	{
		approxPolyDP(contours[i],hull[i],3,true);
		rect[i]=boundingRect(hull[i]);
		minEnclosingCircle(hull[i],center[i],radius[i]);
		rect_[i] = minAreaRect(hull[i]);
		if(hull[i].size()>5)
		{
			ellipsee[i] = fitEllipse(Mat(hull[i]));
		}
	}

	for(int i=0;i<hull.size();i++)
	{
		// Point2f pts[4];
		// rect_[i].points(pts);
		// for(int j=0;j<4;j++)
		// {
		// 	line(src,pts[j],pts[(j+1)%4],Scalar(0,0,255),1,LINE_AA);
		// }


		ellipse(src,ellipsee[i],Scalar(0,0,255),1,LINE_AA);
		//drawContours(dst,hull,i,Scalar(0,0,255),1,LINE_AA);
		//rectangle(src,rect[i],Scalar(0,0,255),1,LINE_AA);
		//circle(src,center[i],radius[i],Scalar(0,0,255),1,LINE_AA);
	}

	imshow("src",src);
}
	

	
