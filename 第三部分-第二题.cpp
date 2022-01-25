#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
    Mat src=imread("/Users/xzk/Desktop/WechatIMG62.jpeg");
    Mat thresh_img;
    Mat open_img;
    Mat gray_img;
    cvtColor(src, gray_img, COLOR_BGR2GRAY);
    threshold(gray_img, thresh_img, 150, 255, THRESH_BINARY);
    morphologyEx(thresh_img, open_img, MORPH_OPEN, getStructuringElement(MORPH_RECT, Size(7,7)));//做一次开运算
    imshow("img", open_img);
    vector<vector<Point>>contours;
    vector<Vec4i>hierarchy;
    findContours(open_img, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);//找到其轮廓
    cout<<contours.size()<<endl;
        drawContours(src , contours, 0, Scalar(40,200,40));
    Rect boundingbox=boundingRect(contours[0]);//寻找最小矩形
    rectangle(src, boundingbox, Scalar(40,40,200),2);
    
    imshow("img", src);
    waitKey(0);
}
