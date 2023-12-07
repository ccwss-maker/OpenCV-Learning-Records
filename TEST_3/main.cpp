#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
#include <iostream>
#include <fstream>

using namespace cv;
using namespace std;
#define X 240
#define Y 320
void ToBin(int num , uint8_t dst[]);
void control(uint8_t k);
uint8_t ToHex(uint8_t num[]);
float times=2.0;
Mat src,dst;
int main()
{
	src = imread("123.jpg", IMREAD_UNCHANGED);
	char output[]="QR.bin";
	control(1);
	resize(src,dst,Size(src.cols/3,src.rows/3));
	imshow(output,dst);
	uint32_t Data0[1]={0};
	int x=dst.cols;
	int y=dst.rows;
	uint8_t Data1[24]={0},x_bin[11]={0},y_bin[11];
	ToBin(y,Data1);
	ToBin(x,Data1+11);
	Data0[0]=0x04;
	Data0[0]|=ToHex(Data1)<<24;
	Data0[0]|=ToHex(Data1+8)<<16;
	Data0[0]|=ToHex(Data1+16)<<8;

	ofstream outFile(output, ios::out | ios::binary);
	outFile.write((char*)Data0,sizeof(Data0));
	for(int row=0;row<dst.rows;row++)
		for(int col=0;col<dst.cols;col++)
		{
			uint8_t b = dst.at<Vec3b>(row,col)[0]/8;
			uint8_t g = dst.at<Vec3b>(row,col)[1]/4;
			uint8_t r = dst.at<Vec3b>(row,col)[2]/8;
			uint16_t rgb=0;
			rgb|=r<<11;
			rgb|=g<<5;
			rgb|=b;
			outFile.write((char*)&rgb,2);
		}
	uint8_t AA=0x0a;
	outFile.write((char*)&AA,1);
	outFile.close();
	waitKey(0);
	destroyAllWindows();
	return 0;
}

void ToBin(int num , uint8_t dst[])
{
	for(int i=0;num>=1;i++)
	{
		dst[10-i]=num%2;
		num/=2;
	}
}

uint8_t ToHex(uint8_t num[])
{
	uint8_t dst=0;
	for(int i=0;i<8;i++)
	{
		dst|=num[i]<<(7-i);
	}
	return dst;
}

void control(uint8_t k)
{
	if(k==1)
	{
		times=src.cols/X;
	}
}