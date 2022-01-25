#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
    Mat img =  imread("/Users/xzk/Desktop/形态学.jpg");
    Mat dst;
    cvtColor(img, img, COLOR_BGR2GRAY);
    threshold(img, dst, 100, 255, THRESH_BINARY);
    Mat dstOpen=dst.clone(),dstClose=dst.clone();
    Mat kernal=getStructuringElement(MORPH_RECT, Size(3,3));
    erode(dstOpen, dstOpen, kernal);//开运算
    dilate(dstOpen, dstOpen, kernal);
    dilate(dstClose, dstClose, kernal);
    erode(dstClose, dstClose, kernal);
    imshow("open", dstOpen);
    imshow("close", dstClose);
    waitKey(0);
    
}
