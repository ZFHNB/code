#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace cv;
using namespace std;

//����������

void ColorSalt(Mat, int);//�����������
void ColorPepper(Mat, int);//�����������
void denoising(Mat);//ͼ��ȥ��
void drawHistogram(string, Mat);//��ֱ��ͼ
void sharpen(Mat);//ͼ����
Mat combinedImages(Mat, Mat);//�ϲ�չʾ����ͼ��


//��������
void ColorSalt(Mat image, int n)//�����������
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
void ColorPepper(Mat image, int n)//�����������
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

void denoising(Mat src)//ͼ��ȥ��
{
	//���뽷������
	ColorSalt(src, 3000);
	ColorPepper(src, 5000);

	Mat dst;
	medianBlur(src, dst, 3);//��ֵ�˲��������Ӵ�СΪ3�� ê��ΪĬ�ϵ��м��
	imshow("����������ֵ�˲��Ľ��", combinedImages(src, dst));

	blur(src, dst, Size(3, 3));//��ֵ�˲��������Ӵ�СΪ3x3�� ê��ΪĬ�ϵ��м��
	imshow("����������ֵ�˲��Ľ��", combinedImages(src, dst));

	GaussianBlur(src, dst, Size(3, 3), 0); // ��˹�˲��������Ӵ�СΪ3x3
	imshow("����������˹�˲��Ľ��", combinedImages(src, dst));
}

//��ֱ��ͼ
void drawHistogram(string detail, Mat src) {
	
	//Mat gray;
	//cvtColor(src, gray, COLOR_BGR2GRAY);

	//��Ҫ�����ͼ���ͨ�����Ҷ�ͼ��Ϊ0��BGRͼ����Ҫָ��B,G,R
	const int channels[] = { 0 };
	Mat hist;//�������Mat����
	int dims = 1;//����ֱ��ͼά��
	const int histSize[] = { 256 }; //ֱ��ͼÿһ��ά�Ȼ��ֵ���������Ŀ
	//ÿһ��ά��ȡֵ��Χ
	float pranges[] = { 0, 255 };//ȡֵ����
	const float* ranges[] = { pranges };

	calcHist(&src, 1, channels, Mat(), hist, dims, histSize, ranges, true, false);//����ֱ��ͼ

	int scale = 2;
	int hist_height = 256;
	Mat histImg = Mat::zeros(hist_height, 256 * scale, CV_8UC3); //����һ���ڵ׵�8λ��3ͨ��ͼ�񣬸�256����256*2
	double max_val;
	minMaxLoc(hist, 0, &max_val, 0, 0);//����ֱ��ͼ���������ֵ
	//�����صĸ������ϵ� ͼ������Χ��
	//����ֱ��ͼ�õ�������
	for (int i = 0; i < 256; i++)
	{
		float bin_val = hist.at<float>(i);   //����histԪ�أ�hist����float���ͣ�
		int intensity = cvRound(bin_val * hist_height / max_val);  //���Ƹ߶�
		rectangle(histImg, Point(i * scale, hist_height - 1), Point((i + 1) * scale - 1, hist_height - intensity), Scalar(255, 255, 255));//����ֱ��ͼ
	}
	// ��ʾֱ��ͼͼ��  
	imshow(detail, histImg);
}

void sharpen(Mat src)
{
	Mat dst, gray, edge;
	GaussianBlur(src, dst, Size(3, 3), 0, 0); //��˹ģ��ȥ������
	cvtColor(dst, gray, COLOR_BGR2GRAY); // �ҶȻ�
	Laplacian(gray, edge, 3, 3); //ʹ��������˹������ȡ��Ե
	convertScaleAbs(edge, edge);
	imshow("������˹����", combinedImages(gray, edge));
}

//�ϲ�չʾ����ͼ��
Mat combinedImages(Mat img1, Mat img2) 
{

	// ����ƴ��ͼ����ܿ�Ⱥ͸߶�
	int totalWidth = img1.cols + img2.cols + 5;//����ͼƬ֮���м�϶
	int maxHeight = img1.rows;

	// ����һ���㹻��Ļ�������������ͼ��
	Mat combinedImage(maxHeight, totalWidth, img1.type(), Scalar(0, 0, 0));

	// ��ͼ���Ƶ���������ȷλ��
	Mat roi1 = combinedImage(Rect(0, 0, img1.cols, img1.rows));
	img1.copyTo(roi1);
	Mat roi2 = combinedImage(Rect(img1.cols + 5, 0, img2.cols, img2.rows));
	img2.copyTo(roi2);

	return combinedImage;
}

int main(int argc, char** argv) {
	Mat src;
	src = imread("����.jpg");
	/*ͼ��ȥ��*/
	//denoising(src);

	/*ֱ��ͼ���⻯*/
	//Mat equlizedImg;//������ž��⻯���ͼ��ľ���
	//Mat gray;
	//cvtColor(src, gray, COLOR_BGR2GRAY);
	//equalizeHist(gray, equlizedImg);//����ֱ��ͼ���⻯
	//imshow("Դͼ��", gray);
	//drawHistogram("���⻯ǰ", gray);
	//imshow("���⻯��ͼ��", equlizedImg);
	//drawHistogram("���⻯��", equlizedImg);

	////ͼ����
	//sharpen(src);

	//ͼ��ָ�
	Mat dividedImg;
	threshold(src, dividedImg, 127, 255, THRESH_BINARY);
	imshow("ͼ��ָ�", combinedImages(src, dividedImg));

	waitKey(0);
	return 0;
}