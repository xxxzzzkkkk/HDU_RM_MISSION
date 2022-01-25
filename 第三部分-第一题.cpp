#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
    Mat src=imread("/Users/xzk/Desktop/WechatIMG61.jpeg");
    Mat img_gray;
    cvtColor(src, img_gray, COLOR_BGR2GRAY);//转为灰度图
    GaussianBlur(img_gray, img_gray, Size(9,9),2,2);//平滑处理

    vector<Vec3f>circles;//存放圆心坐标，半径
    HoughCircles(img_gray, circles, HOUGH_GRADIENT, 1, 10,100,50,0,0);//霍夫变换检测圆
   cout<<circles.size()<<endl;
   for(size_t i=0;i<circles.size();i++){
       Point center(cvRound(circles[i][0]),cvRound(circles[i][1]));
        int radius=cvRound(circles[i][2]);
     circle(src, center, radius, Scalar(40,200,40),-1);//绘制圆填充
  }
   imshow("img", src);
   
    waitKey(0);
}

