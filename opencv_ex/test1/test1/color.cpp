#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat src = imread("D:/a-std and work file/code_git/opencv_ex/test1/test1/lena.jpg");
	imshow("源图像", src);

    Mat dst1, dst2, dst3;
    cvtColor(src, dst1, COLOR_BGR2GRAY);
    cvtColor(src, dst2, COLOR_BGR2HSV);
    cvtColor(src, dst3, COLOR_BGR2YUV);
    imshow("灰度图", dst1); 
    imshow("HSV", dst2);
    imshow("YUV", dst3);

    // 平滑和锐化
    Mat kernel = (Mat_<float>(3, 3) << -1, -1, -1,
        1, 9, 1,
        -1, -1, -1);
    Mat dst4;
    filter2D(src, dst4, -1, kernel);
    imshow("平滑和锐化", dst4);

    // 彩色平衡
    vector<Mat> channels(3);
    split(src, channels);
    Scalar meanValues = mean(src);
    cout << "Mean B value: " << meanValues[0] << endl;
    cout << "Mean G value: " << meanValues[1] << endl;
    cout << "Mean R value: " << meanValues[2] << endl;

    // 需要调整的BGR分量的增益
    double gainB = 1.1; // 蓝色分量的增益
    double gainG = 1.2; // 绿色分量的增益
    double gainR = 1.3; // 红色分量的增益

    // 调整BGR三个通道各自的值
    channels[0] *= gainB;
    channels[1] *= gainG;
    channels[2] *= gainR;

    // BGR三通道图像合并
    Mat result;
    merge(channels, result);

    // 显示调整后的结果
    imshow("Adjusted", result);

	waitKey(0);
	return 0;
}