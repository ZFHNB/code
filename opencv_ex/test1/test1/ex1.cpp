#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>
#include<stdio.h>
#include"ex1.h"
using namespace cv;
using namespace std;

//��Сͼ��
void n1()
{
	//Matrix����
	//src����Դͼ��(����)
	Mat src = imread("D:/lena.jpg", 0);

	if (src.empty())
	{
		perror("imread");
		exit(1);
	}

	imshow("Դͼ��", src);
	Mat dst;//���ͼ��(����)
	resize(src, dst, Size(src.cols / 2, src.rows / 2), INTER_LINEAR);
	imshow("��С��ͼ��", dst);
	waitKey(0);
}

//�Ŵ�ͼ��
void n2()
{
	Mat src = imread("D:/lena.jpg", 0);

	if (src.empty())
	{
		perror("imread");
		exit(1);
	}

	imshow("Դͼ��", src);
	Mat dst;
	resize(src, dst, Size(src.cols * 2, src.rows * 2), INTER_LINEAR);
	imshow("�Ŵ��ͼ��", dst);
	waitKey(0);
}