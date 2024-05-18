#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>
#include<stdio.h>
#include"ex1.h"
using namespace cv;
using namespace std;

//缩小图像
void n1()
{
	//Matrix矩阵
	//src输入源图像(矩阵)
	Mat src = imread("D:/lena.jpg", 0);

	if (src.empty())
	{
		perror("imread");
		exit(1);
	}

	imshow("源图像", src);
	Mat dst;//输出图像(矩阵)
	resize(src, dst, Size(src.cols / 2, src.rows / 2), INTER_LINEAR);
	imshow("缩小后图像", dst);
	waitKey(0);
}

//放大图像
void n2()
{
	Mat src = imread("D:/lena.jpg", 0);

	if (src.empty())
	{
		perror("imread");
		exit(1);
	}

	imshow("源图像", src);
	Mat dst;
	resize(src, dst, Size(src.cols * 2, src.rows * 2), INTER_LINEAR);
	imshow("放大后图像", dst);
	waitKey(0);
}