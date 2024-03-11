#include <opencv2/opencv.hpp>

#include "transforms.h"

int main(){
    Transforms transforms = Transforms();
    cv::Mat image = cv::imread("/Users/huytrq/Workspace/unicas/ImageAnalysisCV/example_images/lowcontrast.png", cv::IMREAD_UNCHANGED);
    cv::Mat output;
    transforms.linear_stretching(image, output);

    cv::imshow("image", image);
    cv::imshow("output", output);
    cv::waitKey(0);
    return 0;
}