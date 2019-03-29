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
		flip(videofeed, videofeed, 1);  //If your RPi camera is fitted upside down, change the third parameter to 0 for vertical flip
                cvtColor(videofeed, grayfeed, COLOR_BGR2GRAY);
		equalizeHist(grayfeed, grayfeed);
        
        vector<Rect> face;
		faceDetector.detectMultiScale(grayfeed, face, 1.1, 5, 0 | CASCADE_FIND_BIGGEST_OBJECT,Size(30, 30));
	
     for (size_t f = 0; f < face.size(); f++)	
	 {
	      rectangle(videofeed, face[f], Scalar(255, 0, 0), 2);
		  putText(videofeed, "Face Detected", Point(face[f].x, face[f].y), FONT_HERSHEY_PLAIN, 1.1, Scalar(0, 255, 0), 1.0);  				
     }
          imshow("Face Detection", videofeed);
		
		if (waitKey(1) >= 0) break;

	}
	return 0;
}
