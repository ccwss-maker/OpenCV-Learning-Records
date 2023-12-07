#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat src,dst,gray,dstt;

int main()
{
	src=imread("xray.jpg",IMREAD_UNCHANGED);
	imshow("src",src);
	
	GaussianBlur(src,src,Size(3,3),0,0,BORDER_DEFAULT);
	cvtColor(src,gray,COLOR_BGR2GRAY);
	
	Laplacian(src,dst,gray.depth(),3);
	convertScaleAbs(dst,dstt);
	//threshold(dstt,dst,128,255,THRESH_TRIANGLE | THRESH_BINARY);
	imshow("dst",dstt);
	
	waitKey(0);
	return 0;
}
	
	
