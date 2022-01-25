#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
    Mat src=imread("/Users/xzk/Desktop/WechatIMG63.jpeg");
    Mat hsv_img,range_img,close_img,blur_img;
    cvtColor(src, hsv_img, COLOR_BGR2HSV);
    blur(hsv_img, blur_img, Size(7,7));//降噪
    inRange(blur_img, Scalar(5,43,165), Scalar(10,240,235), range_img);
    morphologyEx(range_img, close_img, MORPH_CLOSE, getStructuringElement(MORPH_RECT, Size(39,39)));//闭运算合并方便找轮廓
    vector<vector<Point>>contours;
    vector<Vec4i>hierachy;
    findContours(close_img, contours, hierachy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    cout<<contours.size()<<endl;
    for(int i=0;i<contours.size();i++){
       Rect box= boundingRect(contours[i]);//最小包围矩阵
        rectangle(src, box, Scalar(40,200,40),2);
    }
    imshow("img", src);
    imshow("gray", hsv_img);
    imshow("range", range_img);
    imshow("close", close_img);
    waitKey(0);
}
