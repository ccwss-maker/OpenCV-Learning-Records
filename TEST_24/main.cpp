#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat src,Gauss,dst,gray,cann,img;

vector<Vec3f> circles;

int main()
{
	src=imread("circle.jpg",IMREAD_UNCHANGED);
	imshow("src",src);
	
	cvtColor(src,dst,COLOR_BGR2GRAY);

	GaussianBlur(dst,Gauss,Size(3,3),0);
	
	imshow("cann",Gauss);
	
	HoughCircles(Gauss,circles,HOUGH_GRADIENT,1,30,100,30,30,100);

	cout<<circles.size()<<endl;

	for(size_t i=0;i<circles.size();i++)
	{
		Vec3f num = circles[i];
		circle(dst,Point(num[0],num[1]),num[2],Scalar(0,0,255),3,LINE_AA);
		//cout<<num[0]<<","<<num[1]<<","<<num[2]<<endl;
	}
	imshow("dst",dst);

	waitKey(0);
	return 0;
}
	

	
