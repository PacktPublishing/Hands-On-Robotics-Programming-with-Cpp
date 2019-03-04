#include <iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include <wiringPi.h>
#define trigger 13
#define echo 12
long startTime;
long stopTime;
using namespace cv;
using namespace std;
void forward()
{
    digitalWrite(0,HIGH);
	digitalWrite(2,LOW);
	digitalWrite(3,HIGH);
	digitalWrite(4,LOW);
}
void backward()
{
	digitalWrite(0,LOW);
	digitalWrite(2,HIGH);
	digitalWrite(3,LOW);
	digitalWrite(4,HIGH);
}
void left()
{
	digitalWrite(0,LOW);
	digitalWrite(2,HIGH);
	digitalWrite(3,HIGH);
	digitalWrite(4,LOW);
}
void right()
{
	digitalWrite(0,HIGH);
	digitalWrite(2,LOW);
	digitalWrite(3,LOW);
	digitalWrite(4,HIGH);
}
void stop()
{
    digitalWrite(0,HIGH);
	digitalWrite(2,HIGH);
	digitalWrite(3,HIGH);
	digitalWrite(4,HIGH);
}

int main()
{	
	wiringPiSetup();
	pinMode(trigger,OUTPUT);
    pinMode(echo, INPUT); 
	pinMode(0,OUTPUT);
	pinMode(2,OUTPUT);
	pinMode(3,OUTPUT);
	pinMode(4,OUTPUT);
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
		
    digitalWrite(trigger,LOW);
    delay(500);

    digitalWrite(trigger,HIGH);
    delayMicroseconds(10);

    digitalWrite(trigger,LOW); 

    while(digitalRead(echo) == LOW);
    startTime = micros();

    while(digitalRead(echo) == HIGH);
    stopTime = micros(); 
 
    long totalTime= stopTime - startTime; 
   
   float distance = (totalTime * 0.034)/2;
	if(distance < 15)
	{
	cout<<"Object close to Robot"<< " " << Mat(p)<< " " <<distance << " cm" << endl;
	stop();
	}
	else{	
      if(x<20 && y< 20)
      {
      cout<<"Object not found"<< " " << Mat(p)<< " " <<distance << " cm" << endl;
      stop();
      }
      if(x > 20 && x < 214 & y > 20 )
      {
      cout<<"LEFT TURN"<< " " << Mat(p)<< " " <<distance << " cm" << endl;
      left();
      }
      if(x > 214 && x < 428)
      {
      cout<<"FORWARD"<< " " << Mat(p)<< " " <<distance << " cm" << endl;
      forward();
      }
      if(x > 428 && x < 640)
      {
      cout<<"RIGHT TURN"<< " " << Mat(p)<< " " <<distance << " cm" << endl;
      right();
      }
    }
	if (waitKey(33) >= 0) break;
	}
	return 0;
}

