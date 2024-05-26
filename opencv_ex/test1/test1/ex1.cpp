#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>
#include<stdio.h>
#include"ex1.h"
using namespace cv;
using namespace std;

// 缩小图像  
void n1()
{
	// 读取图像，0表示以灰度模式加载  
	Mat src = imread("D:/lena.jpg", 0);
	if (src.empty())
	{ 
		perror("imread");
		exit(1);
	}
	imshow("源图像", src);

	Mat dst;

	// 缩小图像，这里使用线性插值（INTER_LINEAR）  
	// 将图像缩小为原来的一半  
	resize(src, dst, Size(src.cols / 2, src.rows / 2), INTER_LINEAR);
	imshow("缩小后图像", dst);

	// 等待用户按键后关闭所有窗口  
	waitKey(0);//参数单位为毫秒
}

// 放大图像  
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

	// 放大图像，这里使用线性插值（INTER_LINEAR）  
	// 将图像放大为原来的两倍  
	resize(src, dst, Size(src.cols * 2, src.rows * 2), INTER_LINEAR);
	imshow("放大后图像", dst);

	waitKey(0);
}

// 图片旋转  
void n3()
{
	Mat src = imread("D:/a-std and work file/code_git/opencv_ex/test1/test1/lena.jpg", 0);
	if (src.empty())
	{
		perror("open src");
		exit(1);
	}
	imshow("源图像", src);

	Mat dst;
	/*创建一个2x3的浮点型矩阵，用于存储旋转矩阵 */
	//CV_32F 表示 32 位浮点数（float）
	//C1 表示一个通道
	Mat rot_mat(2, 3, CV_32FC1);

	// 计算旋转中心（图像的中心点）  
	Point center(src.rows / 2, src.cols / 2);

	// 旋转角度  
	double angle = 30;

	// 缩放因子,这里旋转后图像大小会变为原来的一半  
	double scale = 0.5;

	// 计算旋转矩阵  
	rot_mat = getRotationMatrix2D(center, angle, scale);

	// 计算旋转后图像的边界矩形  
	Rect bbox = RotatedRect(center, Size(src.rows * scale, src.cols * scale), angle).boundingRect();

	// 调整旋转矩阵，使得旋转后的图像能够完全显示在目标矩形中  
	rot_mat.at<double>(0, 2) += bbox.width / 2.0 - center.x;
	rot_mat.at<double>(1, 2) += bbox.height / 2.0 - center.y;

	// 应用仿射变换，实现图像旋转  
	warpAffine(src, dst, rot_mat, bbox.size());
	imshow("变换图", dst);

	waitKey(0);
}

//图像翻转
void n4()
{
	Mat src = imread("D:/a-std and work file/code_git/opencv_ex/test1/test1/lena.jpg", 0);
	if (src.empty())
	{
		perror("open src");
		exit(1);
	}
	imshow("源图像", src);

	Mat dst;
	resize(src, dst, Size(src.cols / 2, src.rows / 2), INTER_LINEAR);

	//图片镜像
	Mat flip_ud;//上下
	Mat flip_lr;//左右
	Mat flip_udlr;//上下左右

	//0上下，正值左右，负值上下左右
	flip(dst, flip_ud, 0);
	flip(dst, flip_lr, 1);
	flip(dst, flip_udlr, -1);

	imshow("上下翻转", flip_ud);
	imshow("左右翻转", flip_lr);
	imshow("上下左右翻转", flip_udlr);

	waitKey(0);
}

//直方图均衡化
void n5()
{
	Mat src = imread("D:/a-std and work file/code_git/opencv_ex/test1/test1/lena.jpg");
	Mat img = src.clone(); // 复制原始图像以备后续显示  
	Mat imageBGR[3]; // 定义一个包含三个Mat对象的数组，用于存储BGR通道的图像  

	// 将一个多通道矩阵分割为单独的单通道数组  
	split(src, imageBGR);
	for (int i = 0; i < 3; i++)
	{
		// 对每个颜色通道进行直方图均衡化  
		equalizeHist(imageBGR[i], imageBGR[i]);
	}
	// 将多个单通道数组合并为一个多通道矩阵  
	merge(imageBGR, 3, src);

	imshow("原图像", img);
	imshow("直方图均衡化后的图像", src);
	waitKey(0);
}

//图像去噪
void ColorSalt(Mat& image, int n)//加入白盐噪声
{
	srand((unsigned)time(NULL));//以当前时间值作为种子值初始化随机数发生器
	for (int k = 0; k < n; k++)//置n个白盐噪声点
	{
		int i = rand() % image.cols;
		int j = rand() % image.rows;
		image.at<Vec3b>(j, i)[0] = 250;
		image.at<Vec3b>(j, i)[1] = 250;
		image.at<Vec3b>(j, i)[2] = 250;
	}
}
void ColorPepper(Mat& image, int n)//加入黑盐噪声
{
	srand((unsigned)time(NULL));//以当前时间值作为种子值初始化随机数发生器
	for (int k = 0; k < n; k++)//置n个黑盐噪声点
	{
		int i = rand() % image.cols;
		int j = rand() % image.rows;
		image.at<Vec3b>(j, i)[0] = 10;
		image.at<Vec3b>(j, i)[1] = 10;
		image.at<Vec3b>(j, i)[2] = 10;
	}
}

void n6()
{
	Mat src = imread("D:/a-std and work file/code_git/opencv_ex/test1/test1/lena.jpg");
	imshow("源图像", src);
	
	//加入噪声
	ColorSalt(src, 5000);
	ColorPepper(src, 2000);
	imshow("带噪声的图像", src);

	Mat dst;
	medianBlur(src, dst, 3);//中值滤波，核算子大小为3， 锚点为默认的中间点
	imshow("中值滤波的结果", dst);

	blur(src, dst, Size(3, 3));//均值铝箔，核算子大小为3， 锚点为默认的中间点
	imshow("均值滤波的结果", dst);

	waitKey(0);
}