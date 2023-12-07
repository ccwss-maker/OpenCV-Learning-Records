#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat src,dst,gray,two;

int main()
{
	src=Mat::zeros(400,400,CV_8UC1);
	
	vector<Point> vert(6);
	vert[0]=Point(120,20);
	vert[1]=Point(300,20);
	vert[2]=Point(350,180);
	vert[3]=Point(300,340);
	vert[4]=Point(120,340);
	vert[5]=Point(70,180);

	for(int i=0;i<6;i++)
	{
		line(src,vert[i],vert[(i+1)%6],Scalar(255,255,255),1,LINE_AA);
	}
	imshow("src",src);
	
	vector<vector<Point>> contours;
	vector<Vec4i> hierachy;
	findContours(src,contours,hierachy,RETR_TREE,CHAIN_APPROX_SIMPLE);

	// dst = Mat::zeros(src.size(),src.type());
	// cout<<contours.size();
	// drawContours(dst,contours,0,Scalar(255,255,255),1,LINE_AA,hierachy,0);
	// imshow("dst",dst);


	Mat raw_dist=Mat::zeros(src.size(),CV_8UC3);
	for(int row=0;row<src.rows;row++)
	{
		for(int col=0;col<src.cols;col++)
		{
			double dist=pointPolygonTest(contours[0],Point(col,row),true);
			if(dist>0)
			{
				raw_dist.at<Vec3b>(row,col)[0]=0;
				raw_dist.at<Vec3b>(row,col)[1]=0;
				raw_dist.at<Vec3b>(row,col)[2]=saturate_cast<uchar>(dist/100*255);
			}
			else if(dist<0)
			{
				raw_dist.at<Vec3b>(row,col)[0]=saturate_cast<uchar>(abs(dist)/100*255);
				raw_dist.at<Vec3b>(row,col)[1]=255;
				raw_dist.at<Vec3b>(row,col)[2]=255;
			}
			else if(dist=0
			{
				raw_dist.at<Vec3b>(row,col)[0]=255;
				raw_dist.at<Vec3b>(row,col)[1]=0;
				raw_dist.at<Vec3b>(row,col)[2]=0;
			}
		}
	}
	

	imshow("dst",raw_dist);
	waitKey(0);
	return 0;
}
	

	
