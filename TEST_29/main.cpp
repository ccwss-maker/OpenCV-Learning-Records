#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;
int histsize[]={180};
float h_range[]={0,180};
float s_range[]={0,256};
float v_range[]={0,256};
const float *histRanges[] = { h_range };
int channel[]={0};
Mat src,src_,Gauss,dst,gray;
MatND hist[2];
vector<Vec3f> circles;

int main()
{
	src=imread("001.jpg",IMREAD_UNCHANGED);
	src_=imread("002.jpg",IMREAD_UNCHANGED);
	resize(src,src,Size(500,500));
	resize(src_,src_,Size(500,500));
	imshow("src",src);
	imshow("src_",src_);
	cvtColor(src,src,COLOR_RGB2HSV);
	cvtColor(src_,src_,COLOR_RGB2HSV);
	

	calcHist(&src,1,channel,Mat(),hist[0],1,histsize,histRanges);
	normalize(hist[0],hist[0],0,255,NORM_MINMAX);

	calcHist(&src_,1,channel,Mat(),hist[1],1,histsize,histRanges);
	normalize(hist[1],hist[1],0,255,NORM_MINMAX);

	calcBackProject(&src_,1,channel,hist[1],dst,histRanges);

	threshold(dst,dst,190,255,THRESH_BINARY);
	imshow("dst",dst);
	waitKey(0);
	return 0;
}
	

	
