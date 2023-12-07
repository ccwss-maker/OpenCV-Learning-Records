#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat src,dst,gray,two;
int main()
{
	src = imread("Tree.jpg", IMREAD_UNCHANGED);
	imshow("image",src);
	cvtColor(src,gray,COLOR_BGR2GRAY);
	imshow("gray",gray);
	adaptiveThreshold(~gray,two,255,ADAPTIVE_THRESH_MEAN_C,THRESH_BINARY,21,0);
	imshow("two",two);
	// Mat str=getStructuringElement(MORPH_RECT,Size(7,7));
	// morphologyEx(two,dst,MORPH_OPEN,str);
	// str=getStructuringElement(MORPH_RECT,Size(3,3));
	// morphologyEx(dst,dst,MORPH_CLOSE,str,Point(-1,-1),3);
	// imshow("456",dst);
	// bitwise_not(dst,dst);
	// imshow("output",dst);

	
	
	waitKey(0);
	return 0;
}


	
	
