#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat src,dst,gray,two;

int main()
{
	src=imread("xray.jpg",IMREAD_UNCHANGED);
	cvtColor(src,gray,COLOR_RGB2GRAY);
	GaussianBlur(gray,gray,Size(3,3),0);
	Canny(gray,two,100,200);
	vector<vector<Point>> contours;
	vector<Vec4i> hierachy;
	findContours(two,contours,hierachy,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);
	vector<vector<Point>> hill(contours.size());

	vector<Moments> mom(contours.size());
	vector<double> area(contours.size());
	vector<double> length(contours.size());
	for(int i=0;i<100;i++)
	{
		approxPolyDP(Mat(contours[i]),hill[i],3,true);
		mom[i]=moments(contours[i],true);
		area[i]=contourArea(contours[i]);
		length[i]=arcLength(contours[i],true);
		cout<<area[i]<<","<<length[i]<<endl;
	}
	imshow("dst",two);
	

	waitKey(0);
	return 0;
}
	

	
