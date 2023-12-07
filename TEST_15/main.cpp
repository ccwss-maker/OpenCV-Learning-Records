#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat src,dst,f1,f2;
int main()
{
	src = imread("NUM.png", IMREAD_UNCHANGED);
	
	//pyrDown(src,dst,Size(src.cols/2,src.rows/2));

	imshow("src",src);
	

	GaussianBlur(src,f1,Size(5,5),11,11);
	GaussianBlur(f1,f2,Size(5,5),11,11);
	subtract(f1,f2,dst,Mat());

	normalize(dst,dst,255,0,NORM_MINMAX);
	imshow("dst",dst);
	waitKey(0);
	return 0;
}


	
	
