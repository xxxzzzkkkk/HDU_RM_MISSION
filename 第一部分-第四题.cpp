#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
Mat img=imread("/Users/xzk/Desktop/通道分离.png");
    vector<Mat>mv;
    split(img, mv);
    imshow("blue", mv[0]);
    imshow("green", mv[0]);
    imshow("red", mv[0]);
    waitKey(0);
}

