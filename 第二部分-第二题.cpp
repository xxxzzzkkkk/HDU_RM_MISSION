#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
    Mat img =  imread("/Users/xzk/Desktop/R-C.jpeg");
    Mat dst;
    cvtColor(img, img, COLOR_BGR2GRAY);
    threshold(img, dst, 175, 255, THRESH_BINARY);
    imshow("threshold", dst);
    waitKey(0);
    
}
