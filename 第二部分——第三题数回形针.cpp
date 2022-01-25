#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(){
    Mat img=imread("/Users/xzk/Desktop/计数jpg.jpg");
    Mat labelImg,stats,centriods;
    cvtColor(img, img, COLOR_BGR2GRAY);
    threshold(img, img, 100, 255, THRESH_BINARY);
    for(int row=0;row<img.rows;row++){
        for(int col=0;col<3;col++)
            img.at<Vec3b>(row,col)=Vec3b(255,255,255);//图片边缘会误判
    }
    bitwise_not(img, img);//将回形针边缘作为联通域
    auto num_objs=connectedComponentsWithStats(img, labelImg, stats, centriods);
    cout<<"Number of objects detected:"<<num_objs-1<<endl;
    RNG rng(12345);//随机颜色
    vector<Vec3b>color(num_objs);
    color[0]=Vec3b(0,0,0);
    for(int i=1;i<num_objs;i++){
        color[i]=Vec3b(rng.uniform(0, 255),rng.uniform(0, 255),rng.uniform(0, 255));
    }
    Mat dst=Mat::zeros(img.size(), CV_8UC3);
    for(int row=0;row<dst.rows;row++){
        for(int col=0;col<dst.cols;col++){
            int label=labelImg.at<int>(row,col);
            dst.at<Vec3b>(row,col)=color[label];
        }
    }
    for(int i=1;i<num_objs;i++){
        Rect rect(stats.at<int>(i,CC_STAT_LEFT),stats.at<int>(i,CC_STAT_TOP),stats.at<int>(i,CC_STAT_WIDTH),stats.at<int>(i,CC_STAT_HEIGHT));
        rectangle(dst, rect, Scalar(40,200,40));
        putText(dst,to_string(i), Point(stats.at<int>(i,CC_STAT_LEFT)-3,stats.at<int>(i,CC_STAT_TOP)-3), FONT_HERSHEY_PLAIN, 1, Scalar(40,200,40));
    }
    imshow("count", dst);
    waitKey(0);
}
