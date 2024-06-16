#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<cstdio>
#include<iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat src;
	src = imread("D:/a-std and work file/code_git/opencv_ex/test1/test1/lena.jpg");
	cvtColor(src, src, COLOR_BGR2GRAY);//תΪ�Ҷ�ͼ

	imshow("Դͼ��", src);
	Mat dst1, dst2;
	Sobel(src, dst1, CV_16S, 1, 0, 3);///ˮƽ��
	Sobel(src, dst2, CV_16S, 0, 1, 3);//��ֱ��

	/*���Ҷ�ֵȡ����ֵ*/
	convertScaleAbs(dst1, dst1);
	convertScaleAbs(dst2, dst2);

	Mat dst;
	addWeighted(dst1, 0.5, dst2, 0.5, 0, dst);//ͼ���ں�

	imshow("ˮƽ��", dst1);
	imshow("��ֱ��", dst2);
	imshow("�񻯻��", dst);

	waitKey(0);
	return 0;
}