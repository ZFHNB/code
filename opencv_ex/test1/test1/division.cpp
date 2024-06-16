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
	imshow("源图像", src);
	//GaussianBlur(src, src, Size(3, 3), 0);
	//Mat dst = Mat(src.size(), 8u, Scalar(0));
	//Canny算子边缘检测
	/*Canny(src, dst, 50, 150);
	imshow("Canny算子", dst);*/
	//固定阈值
	/*Mat dst;
	Scalar T = mean(src);
	threshold(src, dst, T[0], 255, 0);
	imshow("固定阈值",dst);*/
	Mat dst2;
	Mat dst3;
	adaptiveThreshold(src, dst2, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 11, 2);//自动阈值分割,邻域均值
	adaptiveThreshold(src, dst3, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 11, 2);//自动阈值分割，高斯邻域
	imshow("j阈值",dst2);
	imshow("g阈值",dst3);

	waitKey(0);
	return 0;
}