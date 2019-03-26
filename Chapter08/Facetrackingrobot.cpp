#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>

using namespace std;
using namespace cv;


int main(void)
{
	wiringPiSetup();
	
	pinMode(0,OUTPUT);
	pinMode(2,OUTPUT);
	pinMode(3,OUTPUT);
	
    softPwmCreate(24,0,100);
    softPwmCreate(27,0,100);
    softPwmCreate(25,0,100);
    softPwmCreate(28,0,100);
	
	CascadeClassifier faceDetector("haarcascade_frontalface_alt2.xml");
	CascadeClassifier eyeDetectorright("haarcascade_righteye_2splits.xml");
	CascadeClassifier eyeDetectorleft("haarcascade_lefteye_2splits.xml");
	CascadeClassifier smileDetector("haarcascade_smile.xml");
	
    VideoCapture vid(0);

	Mat videofeed, grayfeed;
	
	if (!vid.isOpened())
    {
    cout<< "Error opening camera"<<endl;
    return -1;
    }

	for(;;)
	{
	vid.read(videofeed);
	flip(videofeed, videofeed, 1);
	cvtColor(videofeed, grayfeed, COLOR_BGR2GRAY);
	equalizeHist(grayfeed, grayfeed);
        
         bool lefteyedetect = false;
         bool righteyedetect = false;
         bool isSmiling = false;
         int facex, facey;
		 
        vector<Rect> face;
		faceDetector.detectMultiScale(grayfeed, face, 1.1, 5, 0 | CASCADE_SCALE_IMAGE,Size(30, 30));
	
     for (size_t f = 0; f < face.size(); f++)	
	 {
	      rectangle(videofeed, face[f], Scalar(255, 0, 0), 2);
		  putText(videofeed, "Face Detected", Point(face[f].x, face[f].y), FONT_HERSHEY_PLAIN, 1.0, Scalar(0, 255, 0), 1.0);  
		  facex = face[f].x +face[f].width/2;
		  facey = face[f].y + face[f].height/2;	
		  Point facecenter(facex, facey);
		  circle(videofeed,facecenter,5,Scalar(255,255,255),-1);
		  
		  Mat faceroi = videofeed(face[f]);	
		  vector<Rect> smile, lefteye, righteye;
		   
		  eyeDetectorleft.detectMultiScale(faceroi, lefteye, 1.3, 25, 0 |CASCADE_SCALE_IMAGE,Size(30, 30));
		  for (size_t le = 0; le < lefteye.size(); le++)
			{
		        Point center(face[f].x + lefteye[le].x + lefteye[le].width*0.5, face[f].y + lefteye[le].y + lefteye[le].height*0.5);
			    int radius = cvRound((lefteye[le].width + lefteye[le].height)*0.25);
				circle(videofeed, center, radius, Scalar(0, 0, 255), 2);
				lefteyedetect = true;
		   }
		   
		  eyeDetectorright.detectMultiScale(faceroi, righteye, 1.3, 25, 0 |CASCADE_SCALE_IMAGE,Size(30, 30));
		  for (size_t re = 0; re < righteye.size(); re++)
			{
		        Point center(face[f].x + righteye[re].x + righteye[re].width*0.5, face[f].y + righteye[re].y + righteye[re].height*0.5);
			    int radius = cvRound((righteye[re].width + righteye[re].height)*0.25);
				circle(videofeed, center, radius, Scalar(255, 255, 0), 2);
				righteyedetect = true;
		   }
				
           smileDetector.detectMultiScale(faceroi, smile, 1.3, 25, 0 |CASCADE_SCALE_IMAGE,Size(30, 30));
           for (size_t sm = 0; sm <smile.size(); sm++)
			{
				Point scenter(face[f].x + smile[sm].x + smile[sm].width*0.5, face[f].y + smile[sm].y + smile[sm].height*0.5);
				int sradius = cvRound((smile[sm].width + smile[sm].height)*0.25);
				circle(videofeed, scenter, sradius, Scalar(0, 255, 0), 2, 8, 0);
				isSmiling = true;
			}		
     }
     
        if(lefteyedetect == true){
		 digitalWrite(0,HIGH);
		 }
		 else
		 {
		digitalWrite(0,LOW);
		 }
		 
        if(righteyedetect == true){
		 digitalWrite(2,HIGH);
		 }
		 else
		 {
		digitalWrite(2,LOW);
		 }
		 
		if(isSmiling == true){
		 digitalWrite(3,HIGH);
		 }
		 else
		 {
		digitalWrite(3,LOW);
		 }
		 
		if(facex > 0 && facex < 280)
			{
		putText(videofeed, "Left", Point(320,10), FONT_HERSHEY_PLAIN, 1.0, CV_RGB(0, 0, 255), 2.0); 
		softPwmWrite(24, 0);
		softPwmWrite(27, 30);
        softPwmWrite(25, 30);
		softPwmWrite(28, 0); 
			}	
			
		if(facex > 360 && facex < 640)
			{
		putText(videofeed, "Right", Point(320,10), FONT_HERSHEY_PLAIN, 1.0, CV_RGB(0, 0, 255), 2.0); 
	    softPwmWrite(24, 30);
        softPwmWrite(27, 0);
        softPwmWrite(25, 0);
        softPwmWrite(28, 30);
		
			}
	    if(facex > 280 && facex < 360)
			{
		putText(videofeed, "Middle", Point(320,10), FONT_HERSHEY_PLAIN, 1.0, CV_RGB(0, 0, 255), 2.0); 
	    softPwmWrite(24, 0);
        softPwmWrite(27, 0);
        softPwmWrite(25, 0);
        softPwmWrite(28, 0);
			}
        imshow("Facial Detection", videofeed);
		
		if (waitKey(1) == 27) break;

	}
	return 0;
}







