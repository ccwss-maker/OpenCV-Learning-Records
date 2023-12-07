#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat src,dst;
int num = 1;
int max_size = 20;
void callback(int,void*);
int main()
{
	src = imread("Tree.jpg", IMREAD_UNCHANGED);
	
	namedWindow("output",WINDOW_AUTOSIZE);

	createTrackbar("element","output",&num,max_size,callback);
	
	waitKey(0);
	return 0;
}

void callback(int,void*)
{
	int s =num*2+1;
	Mat str=getStructuringElement(MORPH_ELLIPSE,Size(s,s));
	morphologyEx(src,dst,MORPH_ERODE,str);
	imshow("output",dst);
}