#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

int main()
{

 Mat img, resizeimg,thresimage;
 img = imread("greenball.png");
 imshow("Green Ball Image", img);
 waitKey(0);
 
 resize(img, resizeimg, cvSize(640, 480));
 imshow("Resized Image"resizeimg);
 waitKey(0);

 inRange(grayimage, Scalar(39, 140, 34), Scalar(122, 245, 119), thresimage);
 imshow("Thresholded Image", thresimage);
 waitKey(0);
 
 Moments m = moments(thresimage,true);
 int x,y;
 x = m.m10/m.m00;
 y = m.m01/m.m00;
 Point p(x,y);
 circle(img, p, 5, Scalar(0,0,200), -1);
 imshow("Image with center",img);
 waitKey(0);

 return 0;
}