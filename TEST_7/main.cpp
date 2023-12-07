#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main()
{
	Mat src1 = imread("003.jpg", IMREAD_UNCHANGED);
	Mat src2 = imread("003_.jpg", IMREAD_UNCHANGED);

	Mat dst;
	double x =0.3;
	//addWeighted(src1,x,src2,(1-x),0,dst);
	multiply(src1,src2,dst,1.0);
	imshow("gray",dst);

	waitKey(0);
	return 0;
}