
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/core.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;
using namespace std;

//importing and displaying image

void main() {
	//string path = "Resources/test.png";
	//Mat img = imread(0);
	VideoCapture cap(0);
	cap.open(0);

	Mat img, grey;

	CascadeClassifier faceCascade;
	faceCascade.load("Resources/haarcascade_frontalface_default.xml");

	if (faceCascade.empty()) { cout << "xml file not loaded" << endl; }
	
	while (true){
		cap >> img;
		//cap.read(img);
		// obtain input image from source
		cap.retrieve(img, CAP_OPENNI_BGR_IMAGE);
		vector<Rect> faces;
	
		cvtColor(img, grey, COLOR_BGR2GRAY);
		faceCascade.detectMultiScale(grey, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(140, 140));

		for (int i = 0; i < faces.size(); i++)
		{
			rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 3);
		}
		imshow("Image", img);
		waitKey(1);
	}
}