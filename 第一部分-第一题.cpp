#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
Mat img=imread("/Users/xzk/Desktop/coins.jpeg");
    for(int row=0;row<img.rows;row++)
    {
        for(int col=0;col<img.cols;col++)
        {
            if(img.channels()==1)
            {
                int pixel=img.at<uchar>(row,col);
                img.at<uchar>(row,col)=255-pixel;
            }
            if(img.channels()==3)
            {
                Vec3b pixel=img.at<Vec3b>(row,col);
                img.at<Vec3b>(row,col)[0]=(pixel[0]+pixel[1]+pixel[2])/3;
                img.at<Vec3b>(row,col)[1]=(pixel[0]+pixel[1]+pixel[2])/3;
                img.at<Vec3b>(row,col)[2]=(pixel[0]+pixel[1]+pixel[2])/3;
                
            }
        }
    }
   
    imshow("average", img);
    waitKey(0);
}
