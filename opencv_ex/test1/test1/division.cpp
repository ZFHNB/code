#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<cstdio>
#include<iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat src = imread("D:/a-std and work file/code_git/opencv_ex/test1/test1/lena.jpg", 0);
	imshow("Դͼ��", src);
	//GaussianBlur(src, src, Size(3, 3), 0);
	//Mat dst = Mat(src.size(), 8u, Scalar(0));
	//Canny���ӱ�Ե���
	/*Canny(src, dst, 50, 150);
	imshow("Canny����", dst);*/
	//�̶���ֵ
	/*Mat dst;
	Scalar T = mean(src);
	threshold(src, dst, T[0], 255, 0);
	imshow("�̶���ֵ",dst);*/
	Mat dst2;
	Mat dst3;
	adaptiveThreshold(src, dst2, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 11, 2);//�Զ���ֵ�ָ�,�����ֵ
	adaptiveThreshold(src, dst3, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 11, 2);//�Զ���ֵ�ָ��˹����
	imshow("j��ֵ",dst2);
	imshow("g��ֵ",dst3);

	waitKey(0);
	return 0;
}