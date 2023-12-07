#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat src,dst,gray;
int aa =127,aa_max=255;
void callback(int,void*);
int main()
{
	src = imread("Tree.jpg",IMREAD_UNCHANGED);
	cvtColor(src,gray,COLOR_RGB2GRAY);
	namedWindow("heihei",WINDOW_AUTOSIZE);
	imshow("gray",gray);

	createTrackbar("haha","heihei",&aa,aa_max,callback);
	waitKey(0);
	return 0;
}

void callback(int,void*)
{
	threshold(gray,dst,aa,aa_max,THRESH_BINARY);
	imshow("heihei",dst);
}

	
	
