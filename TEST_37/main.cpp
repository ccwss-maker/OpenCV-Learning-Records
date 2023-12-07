#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat GrayOut;
	Mat image = Mat::zeros(Size(500,500),CV_8UC3);
	
	image=Scalar(256,224,24);
	imshow("image", image);

	while (true)
	{
		if (waitKey(10) == 27)
		{
			break;
		}
	}
	destroyAllWindows();
	return 0;
}