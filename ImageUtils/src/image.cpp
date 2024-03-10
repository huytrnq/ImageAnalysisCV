#include "image.h"

Image::Image(const std::string &image_path) : image(cv::imread(image_path))
{
    if (image.empty()) throw cv::Exception();
}

void Image::show(const std::string &window_name)
{
    cv::imshow(window_name, image);
    cv::waitKey(0);
}

