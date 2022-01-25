#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
    cout << rand() << endl;
    Mat img = imread("/Users/xzk/Desktop/形态学.jpg");
    if (img.empty())
        cout << "empty" << endl;
    else {
        imshow("img",img);
        Mat labelsImg,stats,centroids;
        cvtColor(img, img, COLOR_BGR2GRAY);
        threshold(img, img, 100, 255, THRESH_BINARY);//二值化
        int num_obj = connectedComponentsWithStats(img, labelsImg, stats, centroids);
        cout << "Number of objects:" << num_obj - 1 << endl;//检测个数（不包括背景）
        vector<Vec3b>color(num_obj);
        color[0] = Vec3b(0, 0, 0);//背景为黑
        for (int i = 1;i < num_obj;i++){
            color[i] = Vec3b((rand() & 255), (rand() & 255), (rand() & 255));
        }//给标记的配上随机颜色
        Mat dst= Mat::zeros(img.size(), CV_8UC3);//创建3通道的与原图大小相同的矩阵
        for (int row = 0;row < dst.rows;row++)
        {
            for (int col = 0;col < dst.cols;col++)
            {
                int lable = labelsImg.at<int>(row, col);//获取标记的数值
                dst.at<Vec3b>(row, col) = color[lable];
            }
        }
        for(int i=1;i<num_obj;i++){
            Rect rect(stats.at<int>(i,CC_STAT_LEFT),stats.at<int>(i,CC_STAT_TOP),stats.at<int>(i,CC_STAT_WIDTH),stats.at<int>(i,CC_STAT_HEIGHT));//通过stats获取bounding box的信息
            rectangle(dst, rect, Scalar(40,200,40));
        }
            
        imshow("connectedcomponent", dst);
        waitKey(0);
    }


}
