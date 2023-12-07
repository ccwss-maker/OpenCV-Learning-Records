#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main()
{
	Mat image = imread("Tree.jpg", IMREAD_UNCHANGED);
	if(!image.data)
	{
		printf("no");
		return -1;
	}

	Mat dst;

	namedWindow("image",WINDOW_AUTOSIZE);
	//imshow("image",image);

	/*
	dst = Mat(image.size(),image.type());
	dst=Scalar(255,0,255);
	*/

	//dst =image.clone();

	// image.copyTo(dst);

	// Mat M(3,3,CV_8UC3,Scalar(0,0,255));

	// Mat dst(30,300,CV_8UC3,Scalar(0,0,255));
	
	//cout <<"M="<<endl<<dst<<endl;

	//Mat dst(image);

	dst.create(100,100,CV_8UC3);
	dst=Scalar(0,255,255);
	imshow("image",dst);

	waitKey(0);
	return 0;
}