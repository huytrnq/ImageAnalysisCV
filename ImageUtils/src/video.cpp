#include "video.h"

Video::Video(const std::string &video_path) : capture(cv::VideoCapture(video_path))
{
    if (!capture.isOpened()) throw cv::Exception();
}

Video::Video(const int &camera_index) : capture(cv::VideoCapture(camera_index))
{
    if (!capture.isOpened()) throw cv::Exception();
}

void Video::show(const std::string &window_name)
{
    cv::Mat frame;
    std::cout << "Press any key to terminate" << std::endl;
    while(capture.read(frame)){
        if (frame.empty()){
            std::cerr << "ERROR! blank frame grabbed\n";
            break;
        }
        cv::imshow(window_name, frame);
        if (cv::waitKey(5) >= 0) break;
    }
}


Video::~Video()
{
}