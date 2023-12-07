#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat src,dst;
int element_size = 1;
int max_size = 21;
void callback_demo(int,void*);
int main()
{
	src = imread("Tree.jpg", IMREAD_UNCHANGED);
	
	namedWindow("output",WINDOW_AUTOSIZE);

	createTrackbar("Element","output",&element_size,max_size,callback_demo);

	waitKey(0);
	return 0;
}

void callback_demo(int,void*)
{
	int s = element_size*2+1;
	Mat str = getStructuringElement(MORPH_ELLIPSE,Size(s,s));
	erode(src,dst,str);
	imshow("output",dst);
}