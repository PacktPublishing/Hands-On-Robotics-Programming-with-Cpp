#include <iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;
int main()
{
	Mat videofeed,resizevideo,thresholdvideo;
	VideoCapture vid(0);
	if (!vid.isOpened())
	{
		return -1;
	}	
	for (;;)
	{		
    vid.read(videofeed);
	resize(videofeed, resizevideo, cvSize(640, 480));
	flip(resizevideo, resizevideo, 1);
	
	inRange(resizevideo, Scalar(39, 140, 34), Scalar(122, 245, 119), thresholdvideo); 

	Moments m = moments(thresholdvideo,true);
	int x,y;
	x = m.m10/m.m00;
	y = m.m01/m.m00;	
	Point p(x,y);
	
	circle(resizevideo, p, 10, Scalar(0,0,128), -1);
	
	imshow("Image with center",resizevideo);
    imshow("Thresolding Video",thresholdvideo);
	
	cout<<Mat(p)<< endl;
	
	if (waitKey(33) >= 0) break;
	}
	return 0;
}


