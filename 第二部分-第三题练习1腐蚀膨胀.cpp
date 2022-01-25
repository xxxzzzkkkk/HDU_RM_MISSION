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
    Mat dstErode,dstdilate=dst.clone();
    Mat kernal=getStructuringElement(MORPH_RECT, Size(3,3));
    erode(dst, dstErode, kernal);
    dilate(dst, dstdilate, kernal);
    imshow("erode", dstErode);
    imshow("dilate", dstdilate);
    waitKey(0);
    
}
