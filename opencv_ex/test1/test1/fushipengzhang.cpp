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
	imshow("Դͼ��", src);

	// ����ṹԪ��
	Mat element = getStructuringElement(MORPH_RECT, Size(3, 3));
	// ��ʴ����
	Mat erosion_output;
	erode(src, erosion_output, element);
	// ���Ͳ���
	Mat dilation_output;
	dilate(src, dilation_output, element);
	// ���������
	Mat opening_output;
	morphologyEx(src, opening_output, MORPH_OPEN, element);
	// ���������
	Mat closing_output;
	morphologyEx(src, closing_output, MORPH_CLOSE, element);
	// ��ʾ���
	imshow("��ʴ", erosion_output);
	imshow("����", dilation_output);
	imshow("��", opening_output);
	imshow("��", closing_output);

	waitKey(0);
	return 0;
}