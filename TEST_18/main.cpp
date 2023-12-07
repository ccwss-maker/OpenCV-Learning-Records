#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat src,dst,gray;

int main()
{
	src=imread("Tree.jpg");
	int topp = (int)(0.05*src.rows);
	int bottomm = (int)(0.05*src.rows);
	int leftt = (int)(0.05*src.cols);
	int rightt = (int)(0.05*src.cols);
	imshow("src",src);
	//copyMakeBorder(src,dst,topp,bottomm,rightt,50,BORDER_WRAP,Scalar(0,0,255));
	GaussianBlur(src,dst,Size(3,3),11,11,BORDER_WRAP);
	imshow("213",dst);
	waitKey(0);
	return 0;
}
	
	
