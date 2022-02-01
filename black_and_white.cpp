#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

using namespace cv;
using namespace std;



int main()

{

 cout << "OpenCV Version : " << CV_VERSION <<endl;

 namedWindow("img-raw", cv::WINDOW_AUTOSIZE);

 namedWindow("img-gray", cv::WINDOW_AUTOSIZE);

 namedWindow("img-canny", cv::WINDOW_AUTOSIZE);



 Mat rawimg, grayimg, cannyimg;
 rawimg = imread("/home/pi/Withus/tmp/mango.jpg", IMREAD_COLOR);
 Mat img_circle;
 rawimg.copyTo(img_circle);
 circle(img_circle, Point(500,100), 50, Scalar(255,0,255),1,8,0);
 circle(img_circle, Point(100,100), 100, Scalar(255,0,0),1,4,0);
 circle(img_circle, Point(200,300), 70, Scalar::all(255),3,8,0);
 circle(img_circle, Point(400,300), 60, Scalar::all(0),-1,8,0);
	img_circle[100:200,100:200]=0;

 //rawimg = imread("/home/pi/Withus/tmp/mango.jpg", IMREAD_COLOR);

 imshow("img-raw", rawimg);



 cvtColor(rawimg, grayimg, cv::COLOR_BGR2GRAY);

 Canny(grayimg, cannyimg, 10, 100, 3, true);

 imshow("img-gray", grayimg);

 imshow("img-canny", cannyimg);

 imshow("img-circle", img_circle);



 waitKey(0);

 destroyAllWindows();



 return 0;

}
