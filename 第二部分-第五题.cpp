#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;
int t1_value=50;
int max_value=255;
Mat gray_img,dst,img;
void onChange(int,void*);

int main(){
    img=imread("/Users/xzk/Desktop/lenna.jpg");
    namedWindow("canny");
    cvtColor(img, gray_img, COLOR_BGR2GRAY);
    GaussianBlur(gray_img, dst, Size(3,3),0,0);
    createTrackbar("value", "canny", &t1_value, max_value,onChange);
    onChange(0, 0);
}
void onChange(int,void*){
    Mat edges_dst,output;
    Canny(dst, edges_dst, t1_value, t1_value*2);
    
    imshow("canny",~edges_dst);
    waitKey(0);
}
