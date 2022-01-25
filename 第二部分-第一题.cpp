#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
  Mat img =  imread("/Users/xzk/Desktop/R-C.jpeg");
    Mat dst;
    cvtColor(img, img, COLOR_BGR2HSV);
    inRange(img, Scalar(35,43,46), Scalar(77,255,255), dst);
    bitwise_not(dst, dst);
    imshow("inrange", dst);
    waitKey(0);
    
}
