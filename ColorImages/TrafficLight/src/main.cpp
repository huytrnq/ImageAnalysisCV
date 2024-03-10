#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

int main(int, char**){
    Mat frame;
    //Initialize videocapture
    VideoCapture cap;
    int deviceID = 0;
    int apiID = cv::CAP_ANY;
    // open selected camera using selected API
    cap.open(deviceID, apiID);
    // check if we succeeded
    if (!cap.isOpened()) {
        cerr << "ERROR! Unable to open camera\n";
        return -1;
    }

    //--- GRAB AND WRITE LOOP
    cout << "Start grabbing" << endl
        << "Press any key to terminate" << endl;
    for (;;)
    {
        // wait for a new frame from camera and store it into 'frame'
        cap.read(frame);
        // check if we succeeded
        if (frame.empty()) {
            cerr << "ERROR! blank frame grabbed\n";
            break;
        }
        //convert to HSV
        Mat hsv;
        cvtColor(frame, hsv, cv::COLOR_BGR2HSV);
        //get h channel
        vector<Mat> channels;
        split(hsv, channels);
        Mat h = channels[0];
        // get heatmap from h channel
        Mat heatmap;
        applyColorMap(h, heatmap, cv::COLORMAP_JET);
        //show the mask
        
        // show live and wait for a key with timeout long enough to show images
        imshow("Live", heatmap);
        if (waitKey(5) >= 0)
            break;
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}