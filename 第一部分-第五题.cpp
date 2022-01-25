#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
    double t=0;
    char string[10];
    double fps=0;
    VideoCapture capture(0);
    Mat frame;
    while (1) {
        t=getTickCount();//系统开启到当前经历的毫秒数
        
        if(capture.isOpened()){
            capture>>frame;
            t=(getTickCount()-t)/getTickFrequency();//这一操作所经历的时间
            fps=1.0/t;
            sprintf(string, "%.2lf",fps);//将fps放入字符串
            putText(frame, string, Point(20,20), FONT_HERSHEY_PLAIN, 2, Scalar(0,0,0));
            imshow("videocapture", frame);
            waitKey(50);
        }
        else{
            cout<<"NO Camera Input"<<endl;
            break;
        }
    }
}
