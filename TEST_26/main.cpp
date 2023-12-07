#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat src,Gauss,dst,gray,cann,img,map_x,map_y;

vector<Vec3f> circles;

int main()
{
	src=imread("xray.jpg",IMREAD_UNCHANGED);
	imshow("src",src);
	
	cvtColor(src,gray,COLOR_RGB2GRAY);
	namedWindow("gray",WINDOW_AUTOSIZE);
	imshow("gray",gray);
	equalizeHist(gray,dst);
	imshow("dst",dst);

	waitKey(0);
	return 0;
}
	

	
