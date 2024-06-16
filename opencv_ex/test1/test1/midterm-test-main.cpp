#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace cv;
using namespace std;

//函数声明：

void ColorSalt(Mat, int);//加入白盐噪声
void ColorPepper(Mat, int);//加入黑盐噪声
void denoising(Mat);//图像去噪
void drawHistogram(string, Mat);//画直方图
void sharpen(Mat);//图像锐化
Mat combinedImages(Mat, Mat);//合并展示两个图像


//椒盐噪声
void ColorSalt(Mat image, int n)//加入白盐噪声
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
void ColorPepper(Mat image, int n)//加入黑盐噪声
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

void denoising(Mat src)//图像去噪
{
	//加入椒盐噪声
	ColorSalt(src, 3000);
	ColorPepper(src, 5000);

	Mat dst;
	medianBlur(src, dst, 3);//中值滤波，核算子大小为3， 锚点为默认的中间点
	imshow("椒盐噪声中值滤波的结果", combinedImages(src, dst));

	blur(src, dst, Size(3, 3));//均值滤波，核算子大小为3x3， 锚点为默认的中间点
	imshow("椒盐噪声均值滤波的结果", combinedImages(src, dst));

	GaussianBlur(src, dst, Size(3, 3), 0); // 高斯滤波，核算子大小为3x3
	imshow("椒盐噪声高斯滤波的结果", combinedImages(src, dst));
}

//画直方图
void drawHistogram(string detail, Mat src) {
	
	//Mat gray;
	//cvtColor(src, gray, COLOR_BGR2GRAY);

	//需要计算的图像的通道，灰度图像为0，BGR图像需要指定B,G,R
	const int channels[] = { 0 };
	Mat hist;//定义输出Mat类型
	int dims = 1;//设置直方图维度
	const int histSize[] = { 256 }; //直方图每一个维度划分的柱条的数目
	//每一个维度取值范围
	float pranges[] = { 0, 255 };//取值区间
	const float* ranges[] = { pranges };

	calcHist(&src, 1, channels, Mat(), hist, dims, histSize, ranges, true, false);//计算直方图

	int scale = 2;
	int hist_height = 256;
	Mat histImg = Mat::zeros(hist_height, 256 * scale, CV_8UC3); //创建一个黑底的8位的3通道图像，高256，宽256*2
	double max_val;
	minMaxLoc(hist, 0, &max_val, 0, 0);//计算直方图的最大像素值
	//将像素的个数整合到 图像的最大范围内
	//遍历直方图得到的数据
	for (int i = 0; i < 256; i++)
	{
		float bin_val = hist.at<float>(i);   //遍历hist元素（hist中是float类型）
		int intensity = cvRound(bin_val * hist_height / max_val);  //绘制高度
		rectangle(histImg, Point(i * scale, hist_height - 1), Point((i + 1) * scale - 1, hist_height - intensity), Scalar(255, 255, 255));//绘制直方图
	}
	// 显示直方图图像  
	imshow(detail, histImg);
}

void sharpen(Mat src)
{
	Mat dst, gray, edge;
	GaussianBlur(src, dst, Size(3, 3), 0, 0); //高斯模糊去除噪声
	cvtColor(dst, gray, COLOR_BGR2GRAY); // 灰度化
	Laplacian(gray, edge, 3, 3); //使用拉普拉斯算子提取边缘
	convertScaleAbs(edge, edge);
	imshow("拉普拉斯算子", combinedImages(gray, edge));
}

//合并展示两个图像
Mat combinedImages(Mat img1, Mat img2) 
{

	// 计算拼接图像的总宽度和高度
	int totalWidth = img1.cols + img2.cols + 5;//让两图片之间有间隙
	int maxHeight = img1.rows;

	// 创建一个足够大的画布来容纳所有图像
	Mat combinedImage(maxHeight, totalWidth, img1.type(), Scalar(0, 0, 0));

	// 将图像复制到画布的正确位置
	Mat roi1 = combinedImage(Rect(0, 0, img1.cols, img1.rows));
	img1.copyTo(roi1);
	Mat roi2 = combinedImage(Rect(img1.cols + 5, 0, img2.cols, img2.rows));
	img2.copyTo(roi2);

	return combinedImage;
}

int main(int argc, char** argv) {
	Mat src;
	src = imread("车牌.jpg");
	/*图像去噪*/
	//denoising(src);

	/*直方图均衡化*/
	//Mat equlizedImg;//创建存放均衡化后的图像的矩阵
	//Mat gray;
	//cvtColor(src, gray, COLOR_BGR2GRAY);
	//equalizeHist(gray, equlizedImg);//进行直方图均衡化
	//imshow("源图像", gray);
	//drawHistogram("均衡化前", gray);
	//imshow("均衡化后图像", equlizedImg);
	//drawHistogram("均衡化后", equlizedImg);

	////图像锐化
	//sharpen(src);

	//图像分割
	Mat dividedImg;
	threshold(src, dividedImg, 127, 255, THRESH_BINARY);
	imshow("图像分割", combinedImages(src, dividedImg));

	waitKey(0);
	return 0;
}