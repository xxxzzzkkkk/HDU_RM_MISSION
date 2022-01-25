#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
Mat srcimg=imread("/Users/xzk/Desktop/晚霞.jpeg");
    Mat deepMat=srcimg.clone();
    Mat shallowMat=srcimg;
    uchar threshold=100;
    for(int row=0;row<srcimg.rows;row++)
    {
        for(int col=0;col<srcimg.cols;col++)
        {
           
                Vec3b pixel=srcimg.at<Vec3b>(row,col);
               uchar average=(pixel[0]+pixel[1]+pixel[2])/3;
               if(average>threshold)
                   average=255;
              else
                  average=0;
                srcimg.at<Vec3b>(row,col)[0]=average;
                srcimg.at<Vec3b>(row,col)[1]=average;
                srcimg.at<Vec3b>(row,col)[2]=average;
                
        }
    }
   
    imshow("deepMat",deepMat);
    imshow("shallowMat",shallowMat);
    waitKey(0);
}
