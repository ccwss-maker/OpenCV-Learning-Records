#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
#include <iostream>
using namespace cv;
int main()
{
    Mat img=imread("C:/Users/hhh20/Desktop/man.jpg");
    imshow("result",img);
    waitKey();
    return 0;
}