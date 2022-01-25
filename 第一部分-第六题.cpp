#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
    Mat img=Mat::zeros(Size(500,500), CV_8UC3);
    rectangle(img, Rect(100,100,100,200), Scalar(255,0,0),2,8,0);//负数为填充正数为线框;
    circle(img, Point(150,150), 50, Scalar(0,255,0),2,8,0);
    line(img, Point(100,100), Point(200,300), Scalar(0,0,255),2);
    imshow("draw", img);
    waitKey(0);
}


