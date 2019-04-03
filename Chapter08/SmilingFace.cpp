#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(void)
{
	CascadeClassifier faceDetector("haarcascade_frontalface_alt2.xml");
	
	CascadeClassifier eyeDetectorright("haarcascade_righteye_2splits.xml");
	
	CascadeClassifier eyeDetector("haarcascade_eye.xml");
	
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
		flip(videofeed, videofeed, 1); //If your RPi camera is fitted upside down, change the third parameter to 0 for vertical flip
        cvtColor(videofeed, grayfeed, COLOR_BGR2GRAY);
		equalizeHist(grayfeed, grayfeed);
        
        vector<Rect> face;
		faceDetector.detectMultiScale(grayfeed, face, 1.1, 5, 0 | CASCADE_FIND_BIGGEST_OBJECT,Size(30, 30));
	
     for (size_t f = 0; f < face.size(); f++)	
	 {
	      rectangle(videofeed, face[f], Scalar(255, 0, 0), 2);
		  putText(videofeed, "Face Detected", Point(face[f].x, face[f].y), FONT_HERSHEY_PLAIN, 1.0, Scalar(0, 255, 0), 1.0);  
		  
		  Mat faceROI = videofeed(face[f]);	
		  vector<Rect> eyes, smile, lefteye, righteye;
		
		eyeDetector.detectMultiScale(faceROI, eyes, 1.3, 5, 0 |CASCADE_SCALE_IMAGE,Size(30, 30));
		  for (size_t e = 0; e < eyes.size(); e++)
			{
		        Point center(face[f].x + eyes[e].x + eyes[e].width*0.5, face[f].y + eyes[e].y + eyes[e].height*0.5);
			    int radius = cvRound((eyes[e].width + eyes[e].height)*0.25);
				circle(videofeed, center, radius, Scalar(0, 0, 255), 2, 8, 0);
		   }
		   
	/* 	eyeDetectorleft.detectMultiScale(faceROI, lefteye, 1.3, 25, 0 |CASCADE_SCALE_IMAGE,Size(30, 30));
		  for (size_t le = 0; le < lefteye.size(); le++)
			{
		        Point center(face[f].x + lefteye[le].x + lefteye[le].width*0.5, face[f].y + lefteye[le].y + lefteye[le].height*0.5);
			    int radius = cvRound((lefteye[le].width + lefteye[le].height)*0.25);
				circle(videofeed, center, radius, Scalar(0, 0, 255), 2, 8, 0);
		   }
		   
		  eyeDetectorright.detectMultiScale(faceROI, righteye, 1.3, 25, 0 |CASCADE_SCALE_IMAGE,Size(30, 30));
		  for (size_t re = 0; re < righteye.size(); re++)
			{
		        Point center(face[f].x + righteye[re].x + righteye[re].width*0.5, face[f].y + righteye[re].y + righteye[re].height*0.5);
			    int radius = cvRound((righteye[re].width + righteye[re].height)*0.25);
				circle(videofeed, center, radius, Scalar(0, 255, 0), 2, 8, 0);
		   }*/
				
          smileDetector.detectMultiScale(faceROI, smile, 1.3, 35, 0 |CASCADE_SCALE_IMAGE,Size(30, 30));
           for (size_t sm = 0; sm <smile.size(); sm++)
			{
				Point scenter(face[f].x + smile[sm].x + smile[sm].width*0.5, face[f].y + smile[sm].y + smile[sm].height*0.5);
				int sradius = cvRound((smile[sm].width + smile[sm].height)*0.25);
				circle(videofeed, scenter, sradius, Scalar(0, 255, 0), 2, 8, 0);
			}		
     }
          imshow("Facial Detection", videofeed);
		
		if (waitKey(1) >= 0) break;

	}
	return 0;
}

