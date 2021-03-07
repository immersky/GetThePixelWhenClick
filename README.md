# GetThePixelWhenClick
get the coordinate of the pixel clicked
# opencv获得鼠标点击像素坐标

鼠标操作涉及两个函数，第一个是cvSetMouseCallback，这个函数注册一个回调函数。使用方法如下：

cvSetMouseCallback("TestWin", TestCallBack, Context); 
前两个参数分别是窗口的名字和回调函数，最后一个参数需要稍微解释一下，这个参数会作为参数传递给回调函数，从而也就可以在主进程与回调函数之间交换上下文。这样就不需要设置大量的全局变量而破坏了整体程序的结构。
鼠标操作需要的回调函数是由开发者自己编写的，这个函数具有下面的原型：

void OnMouse(int event, int x, int y, int flags, void* param); 
观察这个函数的参数，第一个参数是event表达了当前的鼠标事件，鼠标事件的类型有如下几种：

 #define CV_EVENT_MOUSEMOVE 0
 #define CV_EVENT_LBUTTONDOWN 1
 #define CV_EVENT_RBUTTONDOWN 2
 #define CV_EVENT_MBUTTONDOWN 3
 #define CV_EVENT_LBUTTONUP 4
 #define CV_EVENT_RBUTTONUP 5
 #define CV_EVENT_MBUTTONUP 6
 #define CV_EVENT_LBUTTONDBLCLK 7
 #define CV_EVENT_RBUTTONDBLCLK 8
 #define CV_EVENT_MBUTTONDBLCLK 9 
定义的名字已经很好解释了其中的定义。第二个、第三个参数给出了当前鼠标的位置。需要注意的是，这个位置不是相对于窗口或者整个屏幕的，而是相对于Image的。当然这个本身和OpenCV显示的方式是一致的，毕竟我们对于窗口的操作是在Image的基础上完成的。
第三个参数告诉我们当前按键的情况，具体标志如下：

 #define CV_EVENT_FLAG_LBUTTON 1
 #define CV_EVENT_FLAG_RBUTTON 2
 #define CV_EVENT_FLAG_MBUTTON 4
 #define CV_EVENT_FLAG_CTRLKEY 8
 #define CV_EVENT_FLAG_SHIFTKEY 16
 #define CV_EVENT_FLAG_ALTKEY 32 
很容易看出，只需要执行(flag & CV_EVENT_FLAG_LBUTTON)的操作就可以检测左键是否按下，对于其他按键也是类似的。

*代码*

```c++
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
	cv::setMouseCallback("original image", onMouse, reinterpret_cast<void*> (img));//注册鼠标操作(回调)函数
	imshow("original image", src);

	waitKey();
	return 0;

}

```

工程文件下载地址 <https://github.com/immersky/GetThePixelWhenClick>



