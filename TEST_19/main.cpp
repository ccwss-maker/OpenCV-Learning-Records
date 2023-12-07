#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat src,dst_x,dst_y,dst,dst_xy,gray,two,dst_xy_;

int main()
{
	src=imread("xray.jpg",IMREAD_UNCHANGED);
	imshow("src",src);
	
	GaussianBlur(src,src,Size(3,3),0,0,BORDER_DEFAULT);
	cvtColor(src,gray,COLOR_BGR2GRAY);
	Sobel(gray,dst_x,gray.depth(),1,0);
	Sobel(gray,dst_y,gray.depth(),0,1);

	convertScaleAbs(dst_x,dst_x);
	convertScaleAbs(dst_y,dst_y);
	addWeighted(dst_x,0.5,dst_y,0.5,0,dst_xy_);
	imshow("x",dst_x);
	imshow("y",dst_y);
	imshow("x+y",dst_xy_);
	
	waitKey(0);
	return 0;
}
	
	
