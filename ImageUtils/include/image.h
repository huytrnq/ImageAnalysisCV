// Image class definition

#ifndef IMAGE_H
#define IMAGE_H

#include <iostream> 
#include <string>
#include <opencv2/opencv.hpp>

class Image
{
    private:
        cv::Mat image;
    public:
        // 1st constructor
        Image(const std::string &image_path);
        // 2nd constructor
        ~Image();

        // methods
        void show(const std::string &window_name="image");
        cv::Mat get_image();
};



#endif // IMAGE_H   