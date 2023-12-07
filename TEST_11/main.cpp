#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main()
{
	Mat src = imread("Tree.jpg", IMREAD_UNCHANGED),dst;
	
	//blur(src,dst,Size(3,3),Point(-1,-1));
	//GaussianBlur(src,dst,Size(3,3),-11,-11);

	//lvbomedianBlur(src,dst,3);

	bilateralFilter(src,dst,3,150,150);
	namedWindow("src",WINDOW_AUTOSIZE);
	namedWindow("dst",WINDOW_AUTOSIZE);
	imshow("src",src);
	imshow("dst",dst);
	waitKey(0);
	return 0;
}