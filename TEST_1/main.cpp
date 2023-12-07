#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat src,dst,gray,two,src_8uc3;
Mat laplacian_,sharp,distance_,dist_8u,contours_;
int main()
{
	src=imread("456.jpg",IMREAD_UNCHANGED);
	
	two=imread("two.jpg",IMREAD_UNCHANGED);
	Mat dist;
	distanceTransform(two,dist,DIST_L2,3);
	normalize(dist,dist,0,1.,NORM_MINMAX);
	threshold(dist,dist,0.4,1,THRESH_BINARY);
	imshow("dist",dist);

	dist.convertTo(dist_8u,CV_8U);
	imshow("dist_8u",dist_8u);

	vector<vector<Point>> contours;
	findContours(dist_8u,contours,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);


	Mat markers=Mat::zeros(dist.size(),CV_32SC1);
	for(int i = 0 ;i<contours.size();i++)
	{
		drawContours(markers,contours,i,Scalar(255,255,255),-1);
	}
	circle(markers,Point(5,5),3,Scalar(255,255,255),-1);
	
	Mat ABC;
	markers.convertTo(ABC,CV_8U);
	imshow("ABC",ABC);

	//cout<<CV_32SC1<<endl<<markers.type();

	watershed(src,markers);
	Mat mark;
	markers.convertTo(mark,CV_8U);
	//bitwise_not(mark,mark);
	// normalize(mark,mark,0,255,NORM_MINMAX);
	imshow("mark",mark);
	waitKey(0);
	return 0;
}
	

	
