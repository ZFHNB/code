//������˹����
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<cstdio>
#include<iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
	cv::Mat src;
	src = cv::imread("D:/a-std and work file/code_git/opencv_ex/test1/test1/lena.jpg");
	cv::imshow("input", src);
	cv::Mat dst, gray, edge;
	cv::GaussianBlur(src, dst, cv::Size(3, 3), 0, 0); //��˹ģ��ȥ������
	cv::cvtColor(dst, gray, cv::COLOR_BGR2GRAY); // �ҶȻ�
	cv::Laplacian(gray, edge, 3, 3); //ʹ��������˹������ȡ��Ե
	cv::convertScaleAbs(edge, edge);
	cv::imshow("output", edge);
	cv::waitKey(0);
	return 0;
}