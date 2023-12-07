#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
#include <iostream>

using namespace cv;

int main()
{
	Mat image = imread("Tree.jpg", IMREAD_UNCHANGED);
	if(!image.data)
	{
		printf("no");
		return -1;
	}

	double t;

	/*
	t=getTickCount();
	int cols=(image.cols-1)*image.channels();
	int offsets=image.channels();
	int rows=image.rows;
	Mat dst =Mat::zeros(image.size(),image.type());
	for(int row=1;row<rows;row++)
	{
		const uchar *previous = image.ptr<uchar>(row-1);
		const uchar *current = image.ptr<uchar>(row);
		const uchar *next = image.ptr<uchar>(row+1);
		uchar *output = dst.ptr<uchar>(row);
		for(int col=1*image.channels();col<cols;col++)
		{
			output[col]=saturate_cast<uchar>(5*current[col]-(current[col-offsets]+current[col+offsets]+previous[col]+next[col]));
		}
	}
	double time_0=(getTickCount()-t)/getTickFrequency();
	*/

	Mat dst_;
	t=getTickCount();
	Mat kernel =(Mat_<char>(3,3)<<0,-1,0,-1,5,-1,0,-1,0);
	filter2D(image,dst_,image.depth(),kernel);		
	double time_0=(getTickCount()-t);
	double time_1=(getTickCount()-t)/getTickFrequency();

	namedWindow("image", WINDOW_AUTOSIZE);
	//namedWindow("dst", WINDOW_AUTOSIZE);
	namedWindow("dst_", WINDOW_AUTOSIZE);
	imshow("image", image);
	//imshow("dst", dst);
	imshow("dst_", dst_);

	printf("t0=%lf\nt1=%lf",time_0,time_1);
	waitKey(0);
	return 0;
}