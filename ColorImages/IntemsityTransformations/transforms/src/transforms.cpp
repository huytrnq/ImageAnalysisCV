#include "transforms.h"

Transforms::Transforms(){};
Transforms::~Transforms(){};

/**
 * @brief Applies linear stretching transformation to the input image.
 * @param input The input image.
 * @param output The output image after applying the transformation.
 */
void Transforms::linear_stretching(const cv::Mat input, cv::Mat &output){
    double min, max;
    // Find the minimum and maximum pixel values
    cv::minMaxLoc(input, &min, &max);
    // Linear stretching transformation
    output = (input - min) * (255.0 / (max - min));
}