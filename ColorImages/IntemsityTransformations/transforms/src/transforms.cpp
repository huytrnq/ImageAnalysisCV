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
    //
    cv::minMaxLoc(input, &min, &max);
    // Linear stretching transformation
    output = (input - min) * (255.0 / (max - min));
}

std::vector<int> Transforms::calculateHistogram(const cv::Mat image){
    std::vector<int> hist (256, 0);
    for (int i = 0; i < image.rows; i++){
        for (int j = 0; j < image.cols; j++)
        {
            hist[(int)image.at<uchar>(i,j)] ++;
        }
    }
    return hist;
}

std::vector<int> Transforms::cumulativeHistogramCal(const std::vector<int> hist){
    std::vector<int> cumulativeHistogram (256, 0);
    for (int i = 1; i < 256; i++){
        cumulativeHistogram[i] = hist[i] + cumulativeHistogram[i-1];
    }
    return cumulativeHistogram;
}

void Transforms::histogram_eq(const cv::Mat input, cv::Mat &output){
    std::vector<int> hist = calculateHistogram(input);
    std::vector<int> cumHist = cumulativeHistogramCal(hist);
    int totalPixels = input.rows * input.cols;
    output = input.clone();
    for (int i = 0; i < output.rows; i++) {
        for (int j = 0; j < output.cols; j++) {
            output.at<uchar>(i, j) = cv::saturate_cast<uchar>((cumHist[input.at<uchar>(i, j)] * 255.0) / totalPixels);
        }
        }
}