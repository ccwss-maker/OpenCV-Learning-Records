#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main()
{
	Mat image = imread("003.jpg", IMREAD_UNCHANGED);
	if(!image.data)
	{
		printf("no");
		return -1;
	}

	Mat dst;

	namedWindow("image",WINDOW_AUTOSIZE);
	imshow("image",image);

	// int rows = image.rows;
	// int cols = image.cols;

    /*单通道
	for(int row = 0 ; row<rows ; row++)
	{
		for(int col = 0 ; col<cols ; col++)
		{
			int gray = image.at<uchar>(row,col);
			image.at<uchar>(row,col)=255-gray;
		}
	}
    */
   //三通道
//    for(int row = 0 ; row<rows ; row++)
// 	{
// 		for(int col = 0 ; col<cols ; col++)
// 		{
// 			int b = image.at<Vec3b>(row,col)[0];
// 			int g = image.at<Vec3b>(row,col)[1];
// 			int r = image.at<Vec3b>(row,col)[2];
// 			image.at<Vec3b>(row,col)[0]=255-b;
// 			image.at<Vec3b>(row,col)[1]=255-g;
// 			image.at<Vec3b>(row,col)[2]=255-r;
// 		}
// 	}
	
	

	bitwise_not(image,dst);

	imshow("gray",dst);

	waitKey(0);
	return 0;
}