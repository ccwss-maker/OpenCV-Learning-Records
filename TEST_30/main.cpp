#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat src,cat,dst;
int main()
{
	cat=imread("cat.jpg",IMREAD_UNCHANGED);
	src=imread("pic.jpg",IMREAD_UNCHANGED);
	resize(src,src,Size(src.cols/3,src.rows/3));
	resize(cat,cat,Size(cat.cols/3,cat.rows/3));
	Mat dst(src.rows-cat.rows,src.cols-cat.cols,CV_32FC1);
	matchTemplate(src,cat,dst,TM_SQDIFF);
	normalize(dst,dst,0,1,NORM_MINMAX);
	double min,max;
	Point min_loc,max_loc;
	minMaxLoc(dst,&min,&max,&min_loc,&max_loc);
	rectangle(src,Rect(min_loc.x,min_loc.y,cat.rows,cat.cols),Scalar(0,0,255),2,LINE_AA);

	imshow("cat",cat);
	imshow("src",src);
	
	waitKey(0);
	return 0;
}
	

	
