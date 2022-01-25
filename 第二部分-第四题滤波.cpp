#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(){
    VideoCapture cap(0);
    Mat frame1,frame2,frame3;
    while(1){
        if(!cap.isOpened()){
            cout<<"Can not find camera"<<endl;
            return 0;
        }
        else{
            cap>>frame1;
            cap>>frame2;
            cap>>frame3;
            namedWindow("medianblur",0);
            resizeWindow("medianblur", 256, 256);
            namedWindow("blur",0);
            resizeWindow("blur", 256, 256);
            namedWindow("Gaussianblur",0);
            resizeWindow("Gaussianblur", 256, 256);
            medianBlur(frame1, frame1, 9);
            flip(frame1, frame1, 1);//左右翻转
            blur(frame2, frame2, Size(5,5));
            flip(frame2, frame2, 1);//左右翻转
            GaussianBlur(frame3, frame3, Size(5,5), 0,0);
            flip(frame3, frame3, 1);//左右翻转
            imshow("medianblur", frame1);
            imshow("blur", frame2);
            imshow("Gaussianblur", frame3);
            waitKey(50);
        }
    }
}
