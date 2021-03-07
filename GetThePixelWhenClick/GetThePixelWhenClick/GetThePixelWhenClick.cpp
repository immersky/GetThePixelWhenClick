// FindTheCornerAuto.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
using namespace cv;
using namespace std;
Mat *img = 0;
void onMouse(int event, int x, int y, int flags, void* param)
{
	Mat *im = reinterpret_cast<Mat*>(param);
	switch (event)
	{
	case 1:     //鼠标左键按下响应：返回坐标和灰度
		std::cout << "at(" << x << "," << y << ")value is:"
			<< static_cast<int>(im->at<uchar>(cv::Point(x, y))) << std::endl;
		break;
	case 2:    //鼠标右键按下响应：输入坐标并返回该坐标的灰度
		std::cout << "input(x,y)" << endl;
		std::cout << "x =" << endl;
		cin >> x;
		std::cout << "y =" << endl;
		cin >> y;
		std::cout << "at(" << x << "," << y << ")value is:"
			<< static_cast<int>(im->at<uchar>(cv::Point(x, y))) << std::endl;
		break;
	}
}

int main()
{

	Mat src = imread("1.jpg");
	img = &src;
	Mat src2 = src.clone();
	namedWindow("original image", WINDOW_AUTOSIZE);
	cv::setMouseCallback("original image", onMouse, reinterpret_cast<void*> (img));
	imshow("original image", src);

	waitKey();
	return 0;

}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
