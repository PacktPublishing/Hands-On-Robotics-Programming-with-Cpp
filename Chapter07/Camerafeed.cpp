#include <iostream>
#include <stdio.h>
#include<opencv2/opencv.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;
int main()
{	Mat videoframe;
	VideoCapture vid(0);
	if (!vid.isOpened())
	{
		cout<<"Error opening camera"<<endl;
		return -1;
	}
	for(;;)
	{
		vid.read(videoframe);
        imshow("Frame", videoframe);
		if (waitKey(1) > 0) break;
	}
	return 0;
}

