#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat src,Gauss,dst,gray,cann,img;

vector<Vec4f> plines;

int main()
{
	src=imread("pic.png",IMREAD_UNCHANGED);
	imshow("src",src);
	
	cvtColor(src,dst,COLOR_BGR2GRAY);

	Canny(src,cann,100,200,3);
	
	imshow("cann",cann);
	
	HoughLinesP(cann,plines,1,CV_PI/180.0,10,10,30);

	cout<<plines.size()<<endl;

	for(size_t i=0;i<plines.size();i++)
	{
		Vec4f hline = plines[i];
		line(dst,Point(hline[0],hline[1]),Point(hline[2],hline[3]),Scalar(0,0,255),3,LINE_AA);
		cout<<hline[0]<<","<<hline[1]<<","<<hline[2]<<","<<hline[3]<<endl;
	}
	imshow("dst",dst);

	waitKey(0);
	return 0;
}
	

	
