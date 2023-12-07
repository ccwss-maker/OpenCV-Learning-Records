#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat src,Gauss,dst,gray,cann,img,map_x,map_y;

vector<Vec3f> circles;

int main()
{
	src=imread("circle.jpg",IMREAD_UNCHANGED);
	imshow("src",src);
	dst=Mat::zeros(src.size(),src.type());
	map_x.create(src.size(),CV_32FC1);
	map_y.create(src.size(),CV_32FC1);
	for(int row=0;row<src.rows;row++)
	{
		for(int col=0;col<src.cols;col++)
		{
			map_x.at<float>(row,col) = static_cast<float>(col);
			map_y.at<float>(row,col) = static_cast<float>(row);
		}
	}

	remap(src,dst,map_x,map_y,INTER_LINEAR,BORDER_CONSTANT,Scalar(255,0,0));
	imshow("dst",dst);

	waitKey(0);
	return 0;
}
	

	
