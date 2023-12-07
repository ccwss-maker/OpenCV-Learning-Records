#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main()
{
	Mat src = imread("Tree.jpg", IMREAD_UNCHANGED);
	
	//cout<<"x="<<src.cols<<endl<<"y="<<src.rows<<endl;
	Point P1=Point(20,30);
	Point P2=Point(src.cols,src.rows);
	
	Scalar red = Scalar(0,0,255);
	line(src,P1,P2,Scalar(0,0,255),2,LINE_AA);
	
	Rect rect = Rect(50,50,200,200);
	rectangle(src,rect,red,2,LINE_8);

	ellipse(src,Point(src.cols/2,src.rows/2),Size(src.cols/4,src.rows/8),0,0,360,red,2,LINE_AA);

	circle(src,Point(300,300),50,red,2,LINE_AA);

	Point pts[2][6];
	const Point * ppts[]={pts[0],pts[1]};
	int npt[]={6,6};
	pts[0][0]=Point(100,100);
	pts[0][1]=Point(100,100);
	pts[0][2]=Point(300,300);
	pts[0][3]=Point(200,350);
	pts[0][4]=Point(100,300);
	pts[0][5]=Point(100,100);

	pts[1][0]=Point(200,100);
	pts[1][1]=Point(200,100);
	pts[1][2]=Point(400,300);
	pts[1][3]=Point(500,350);
	pts[1][4]=Point(200,300);
	pts[1][5]=Point(200,100);
	fillPoly(src,ppts,npt,2,red,LINE_AA);

	putText(src,"HELLO",Point(400,400),FONT_HERSHEY_COMPLEX,1.0,red,1,16);

	RNG rng(12345);
	for(int i=0;i<500000;i++)
	{
		Point P1=Point(rng.uniform(0,src.cols),rng.uniform(0,src.rows));
		Point P2=Point(rng.uniform(0,src.cols),rng.uniform(0,src.rows));
		line(src,P1,P2,Scalar(rng.uniform(0,255),rng.uniform(0,255),rng.uniform(0,255)),1,LINE_AA);
		imshow("gray",src);
	}

	imshow("gray",src);
	waitKey(0);
	return 0;
}