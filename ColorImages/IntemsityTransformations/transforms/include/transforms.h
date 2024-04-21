#include <iostream>
#include <vector>

#include <opencv2/opencv.hpp>

/**
 * @class Transforms
 * @brief Class for performing intensity transformations on images.
 */
class Transforms{
    
    private:
        // For log transformation
        int L;
    public:
        /**
         * @brief Default constructor for Transforms class.
         */
        Transforms();
        
        /**
         * @brief Destructor for Transforms class.
         */
        ~Transforms();

        /**
         * @brief Applies linear stretching transformation to the input image.
         * @param input The input image.
         * @param output The output image after applying the transformation.
         */
        void linear_stretching(const cv::Mat input, cv::Mat &output);

        std::vector<int> calculateHistogram(const cv::Mat image);
        std::vector<int> cumulativeHistogramCal(const std::vector<int> hist);
        void histogram_eq(const cv::Mat input, cv::Mat &output);
};