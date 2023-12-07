#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;
int histsize=256;
float range[]={0,256};
const float *histRanges = { range };
Mat src,Gauss,dst,gray;

vector<Vec3f> circles;

int main()
{
	src=imread("Tree.jpg",IMREAD_UNCHANGED);
	imshow("src",src);
	
	Mat img[3];
	split(src,img);
	int aaa=0;
	Mat b_list;
	calcHist(&src,1,&aaa,Mat(),b_list,1,&histsize,&histRanges);

	cout<<b_list.size()<<b_list<<endl;
	waitKey(0);
	return 0;
}
	

	
