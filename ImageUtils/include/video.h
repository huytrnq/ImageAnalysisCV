// Opencv video processing head
#ifndef VIDEO_H
#define VIDEO_H

#include <iostream>
#include <string>
#include <stdio.h>

#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>


class Video
{
    cv::VideoCapture capture;
    int cap_height = capture.get(cv::CAP_PROP_FRAME_HEIGHT);
    int cap_width = capture.get(cv::CAP_PROP_FRAME_WIDTH);
    private: 
        /* data */
        int apiID = cv::CAP_ANY; 
    public:
        // 1st constructor
        Video(const std::string &video_path);
        // 2nd constructor
        Video(const int &camera_index);
        ~Video();

        // methods
        void show(const std::string &window_name="video");
};



#endif // VIDEO_H