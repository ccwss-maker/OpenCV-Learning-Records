#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat src,dst,gray,dstt,img;
void callback(int,void*);
int value=50,value_max=255;
int main()
{
	src=imread("xray.jpg",IMREAD_UNCHANGED);
	imshow("src",src);
	namedWindow("dst",WINDOW_AUTOSIZE);
	GaussianBlur(src,src,Size(3,3),0,0,BORDER_DEFAULT);
	cvtColor(src,gray,COLOR_BGR2GRAY);
	Sobel(gray,img,gray.depth(),1,0);
	createTrackbar("123","dst",&value,value_max,callback);
	
	waitKey(0);
	return 0;
}
	
void callback(int,void*)
{
	Canny(img,dst,value,value*3,3);
	imshow("dst",dst);
}
	
