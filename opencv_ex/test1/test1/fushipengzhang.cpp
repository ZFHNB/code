#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<cstdio>
#include<iostream>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

int main()
{
	Mat src = imread("D:/a-std and work file/code_git/opencv_ex/test1/test1/lena.jpg", 0);
	imshow("源图像", src);

	// 定义结构元素
	Mat element = getStructuringElement(MORPH_RECT, Size(3, 3));
	// 腐蚀操作
	Mat erosion_output;
	erode(src, erosion_output, element);
	// 膨胀操作
	Mat dilation_output;
	dilate(src, dilation_output, element);
	// 开运算操作
	Mat opening_output;
	morphologyEx(src, opening_output, MORPH_OPEN, element);
	// 闭运算操作
	Mat closing_output;
	morphologyEx(src, closing_output, MORPH_CLOSE, element);
	// 显示结果
	imshow("腐蚀", erosion_output);
	imshow("膨胀", dilation_output);
	imshow("开", opening_output);
	imshow("闭", closing_output);

	waitKey(0);
	return 0;
}