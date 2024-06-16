#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat src = imread("D:/a-std and work file/code_git/opencv_ex/test1/test1/lena.jpg");
	imshow("Դͼ��", src);

    Mat dst1, dst2, dst3;
    cvtColor(src, dst1, COLOR_BGR2GRAY);
    cvtColor(src, dst2, COLOR_BGR2HSV);
    cvtColor(src, dst3, COLOR_BGR2YUV);
    imshow("�Ҷ�ͼ", dst1); 
    imshow("HSV", dst2);
    imshow("YUV", dst3);

    // ƽ������
    Mat kernel = (Mat_<float>(3, 3) << -1, -1, -1,
        1, 9, 1,
        -1, -1, -1);
    Mat dst4;
    filter2D(src, dst4, -1, kernel);
    imshow("ƽ������", dst4);

    // ��ɫƽ��
    vector<Mat> channels(3);
    split(src, channels);
    Scalar meanValues = mean(src);
    cout << "Mean B value: " << meanValues[0] << endl;
    cout << "Mean G value: " << meanValues[1] << endl;
    cout << "Mean R value: " << meanValues[2] << endl;

    // ��Ҫ������BGR����������
    double gainB = 1.1; // ��ɫ����������
    double gainG = 1.2; // ��ɫ����������
    double gainR = 1.3; // ��ɫ����������

    // ����BGR����ͨ�����Ե�ֵ
    channels[0] *= gainB;
    channels[1] *= gainG;
    channels[2] *= gainR;

    // BGR��ͨ��ͼ��ϲ�
    Mat result;
    merge(channels, result);

    // ��ʾ������Ľ��
    imshow("Adjusted", result);

	waitKey(0);
	return 0;
}