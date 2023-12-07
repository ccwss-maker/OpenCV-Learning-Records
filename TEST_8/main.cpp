#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main()
{
	Mat src = imread("003_.jpg", IMREAD_UNCHANGED);

	Mat dst = Mat(src.size(),src.type());
	imshow("src",src);
	int cols = src.cols;
	int rows = src.rows;

	float x = 0.5;
	float y =20;
	for(int row= 0 ;row<rows;row++)
	{
		for(int col=0 ; col<cols;col++)
		{
			int b=src.at<Vec3b>(row,col)[0];
			int g=src.at<Vec3b>(row,col)[1];
			int r=src.at<Vec3b>(row,col)[2];
			dst.at<Vec3b>(row,col)[0]=saturate_cast<uchar>(x*b+y);
			dst.at<Vec3b>(row,col)[1]=saturate_cast<uchar>(x*g+y);
			dst.at<Vec3b>(row,col)[2]=saturate_cast<uchar>(x*r+y);
		}
	}
	
	imshow("gray",dst);

	waitKey(0);
	return 0;
}