#include <iostream>
#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;
int main()
{

Mat img;

img = imread("Car.jpg");

imshow("Car Image", img);

waitKey(0);

return 0;
}