#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;
int histsize[]={180,256,256};
float h_range[]={0,180};
float s_range[]={0,256};
float v_range[]={0,256};
const float *histRanges[] = { h_range,s_range,v_range };
int channel[]={0,1,2};
Mat src,src_,Gauss,dst,gray;
Mat hist[2];
vector<Vec3f> circles;

int main()
{
	src=imread("001.jpg",IMREAD_UNCHANGED);
	src_=imread("002.jpg",IMREAD_UNCHANGED);
	resize(src,src,Size(500,500));
	resize(src_,src_,Size(500,500));
	cvtColor(src,src,COLOR_RGB2HSV);
	cvtColor(src_,src_,COLOR_RGB2HSV);
	imshow("src",src);
	imshow("src_",src_);

	calcHist(&src,1,channel,Mat(),hist[0],3,histsize,histRanges);
	normalize(hist[0],hist[0],0,1,NORM_MINMAX);

	calcHist(&src_,1,channel,Mat(),hist[1],3,histsize,histRanges);
	normalize(hist[1],hist[1],0,1,NORM_MINMAX);

	cout<<compareHist(hist[0],hist[1],HISTCMP_CHISQR)<<endl;
	waitKey(0);
	return 0;
}
	

	
