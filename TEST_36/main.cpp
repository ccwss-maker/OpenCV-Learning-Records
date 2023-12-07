#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat src,dst,gray,two;
Mat laplacian_,sharp,distance_,distance_8u,contours_;
int main()
{
	src=imread("003.jpg",IMREAD_UNCHANGED);
	resize(src,src,Size(src.cols/4,src.rows/4));
	for(int row=0;row<src.rows;row++)
	{
		for(int col=0;col<src.cols;col++)
		{
			if(src.at<Vec3b>(row,col)[0]>252&&src.at<Vec3b>(row,col)[1]>252&&src.at<Vec3b>(row,col)[2]>252)
			{
				src.at<Vec3b>(row,col)[0]=0;
				src.at<Vec3b>(row,col)[1]=0;
				src.at<Vec3b>(row,col)[2]=0;
			}
		}
	}

	Mat kernel = getStructuringElement(MORPH_ELLIPSE,Size(3,3));
	morphologyEx(src,src,MORPH_OPEN,kernel);
	imshow("src",src);

	Laplacian(src,laplacian_,CV_32F,3);
	src.convertTo(sharp,CV_32F);
	sharp=sharp-laplacian_;
	sharp.convertTo(sharp,CV_8UC3);
	imshow("laplacian",sharp);

	cvtColor(sharp,gray,COLOR_RGB2GRAY);
	imshow("gray",gray);
	threshold(gray,two,220,255,THRESH_BINARY);
	imshow("two",two);
	
	distanceTransform(two,distance_,DIST_L2,3);
	normalize(distance_,distance_,0,1,NORM_MINMAX);
	//threshold(distance_,distance_,0.4,1,THRESH_BINARY);
	
	
	
	distance_.convertTo(distance_8u,CV_8U);
	imshow("distance_8u",distance_8u);
	vector<vector<Point>> contours;
	findContours(distance_8u,contours,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);

	Mat distance_num=Mat::zeros(src.size(),CV_32S);
	for(int i = 0 ;i<contours.size();i++)
	{
		drawContours(distance_num,contours,static_cast<int>(i),Scalar::all(i+1),-1);
	}
	Mat ABC;
	distance_num.convertTo(ABC,CV_8U);
	imshow("distance_num",ABC);

	watershed(src,distance_num);
	Mat mark;
	distance_num.convertTo(mark,CV_8UC1);
	bitwise_not(mark,mark);
	imshow("marks",mark);
	dst=Mat::zeros(src.size(),CV_8UC3);
	for(int row=0;row<distance_num.rows;row++)
	{
		for(int col=0;col<distance_num.cols;col++)
		{
			int a=distance_num.at<int>(row,col);
			if(a>=0&&a<=contours.size())
			{
				dst.at<Vec3b>(row,col)=Vec3b(a*20+30,100,a*20+30);
			}
			else
			{
				dst.at<Vec3b>(row,col)=Vec3b(0,0,0);
			}
		}
	}

	imshow("dst",dst);

	waitKey(0);
	return 0;
}
	

	
