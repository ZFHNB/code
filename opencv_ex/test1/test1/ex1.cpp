#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>
#include<stdio.h>
#include"ex1.h"
using namespace cv;
using namespace std;

// ��Сͼ��  
void n1()
{
	// ��ȡͼ��0��ʾ�ԻҶ�ģʽ����  
	Mat src = imread("D:/lena.jpg", 0);
	if (src.empty())
	{ 
		perror("imread");
		exit(1);
	}
	imshow("Դͼ��", src);

	Mat dst;

	// ��Сͼ������ʹ�����Բ�ֵ��INTER_LINEAR��  
	// ��ͼ����СΪԭ����һ��  
	resize(src, dst, Size(src.cols / 2, src.rows / 2), INTER_LINEAR);
	imshow("��С��ͼ��", dst);

	// �ȴ��û�������ر����д���  
	waitKey(0);//������λΪ����
}

// �Ŵ�ͼ��  
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

	// �Ŵ�ͼ������ʹ�����Բ�ֵ��INTER_LINEAR��  
	// ��ͼ��Ŵ�Ϊԭ��������  
	resize(src, dst, Size(src.cols * 2, src.rows * 2), INTER_LINEAR);
	imshow("�Ŵ��ͼ��", dst);

	waitKey(0);
}

// ͼƬ��ת  
void n3()
{
	Mat src = imread("D:/a-std and work file/code_git/opencv_ex/test1/test1/lena.jpg", 0);
	if (src.empty())
	{
		perror("open src");
		exit(1);
	}
	imshow("Դͼ��", src);

	Mat dst;
	/*����һ��2x3�ĸ����;������ڴ洢��ת���� */
	//CV_32F ��ʾ 32 λ��������float��
	//C1 ��ʾһ��ͨ��
	Mat rot_mat(2, 3, CV_32FC1);

	// ������ת���ģ�ͼ������ĵ㣩  
	Point center(src.rows / 2, src.cols / 2);

	// ��ת�Ƕ�  
	double angle = 30;

	// ��������,������ת��ͼ���С���Ϊԭ����һ��  
	double scale = 0.5;

	// ������ת����  
	rot_mat = getRotationMatrix2D(center, angle, scale);

	// ������ת��ͼ��ı߽����  
	Rect bbox = RotatedRect(center, Size(src.rows * scale, src.cols * scale), angle).boundingRect();

	// ������ת����ʹ����ת���ͼ���ܹ���ȫ��ʾ��Ŀ�������  
	rot_mat.at<double>(0, 2) += bbox.width / 2.0 - center.x;
	rot_mat.at<double>(1, 2) += bbox.height / 2.0 - center.y;

	// Ӧ�÷���任��ʵ��ͼ����ת  
	warpAffine(src, dst, rot_mat, bbox.size());
	imshow("�任ͼ", dst);

	waitKey(0);
}

//ͼ��ת
void n4()
{
	Mat src = imread("D:/a-std and work file/code_git/opencv_ex/test1/test1/lena.jpg", 0);
	if (src.empty())
	{
		perror("open src");
		exit(1);
	}
	imshow("Դͼ��", src);

	Mat dst;
	resize(src, dst, Size(src.cols / 2, src.rows / 2), INTER_LINEAR);

	//ͼƬ����
	Mat flip_ud;//����
	Mat flip_lr;//����
	Mat flip_udlr;//��������

	//0���£���ֵ���ң���ֵ��������
	flip(dst, flip_ud, 0);
	flip(dst, flip_lr, 1);
	flip(dst, flip_udlr, -1);

	imshow("���·�ת", flip_ud);
	imshow("���ҷ�ת", flip_lr);
	imshow("�������ҷ�ת", flip_udlr);

	waitKey(0);
}

//ֱ��ͼ���⻯
void n5()
{
	Mat src = imread("D:/a-std and work file/code_git/opencv_ex/test1/test1/lena.jpg");
	Mat img = src.clone(); // ����ԭʼͼ���Ա�������ʾ  
	Mat imageBGR[3]; // ����һ����������Mat��������飬���ڴ洢BGRͨ����ͼ��  

	// ��һ����ͨ������ָ�Ϊ�����ĵ�ͨ������  
	split(src, imageBGR);
	for (int i = 0; i < 3; i++)
	{
		// ��ÿ����ɫͨ������ֱ��ͼ���⻯  
		equalizeHist(imageBGR[i], imageBGR[i]);
	}
	// �������ͨ������ϲ�Ϊһ����ͨ������  
	merge(imageBGR, 3, src);

	imshow("ԭͼ��", img);
	imshow("ֱ��ͼ���⻯���ͼ��", src);
	waitKey(0);
}

//ͼ��ȥ��
void ColorSalt(Mat& image, int n)//�����������
{
	srand((unsigned)time(NULL));//�Ե�ǰʱ��ֵ��Ϊ����ֵ��ʼ�������������
	for (int k = 0; k < n; k++)//��n������������
	{
		int i = rand() % image.cols;
		int j = rand() % image.rows;
		image.at<Vec3b>(j, i)[0] = 250;
		image.at<Vec3b>(j, i)[1] = 250;
		image.at<Vec3b>(j, i)[2] = 250;
	}
}
void ColorPepper(Mat& image, int n)//�����������
{
	srand((unsigned)time(NULL));//�Ե�ǰʱ��ֵ��Ϊ����ֵ��ʼ�������������
	for (int k = 0; k < n; k++)//��n������������
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
	imshow("Դͼ��", src);
	
	//��������
	ColorSalt(src, 5000);
	ColorPepper(src, 2000);
	imshow("��������ͼ��", src);

	Mat dst;
	medianBlur(src, dst, 3);//��ֵ�˲��������Ӵ�СΪ3�� ê��ΪĬ�ϵ��м��
	imshow("��ֵ�˲��Ľ��", dst);

	blur(src, dst, Size(3, 3));//��ֵ�����������Ӵ�СΪ3�� ê��ΪĬ�ϵ��м��
	imshow("��ֵ�˲��Ľ��", dst);

	waitKey(0);
}