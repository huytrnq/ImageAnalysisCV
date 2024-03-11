#include <opencv2/opencv.hpp>

#include "image.h"

using namespace std;
using namespace cv;

void show(const string &winname, const Mat &image){
    imshow(winname, image);
    waitKey(0);
}


int main(int argc, char** argv){ 
    Image image = Image("/Users/huytrq/Workspace/unicas/ImageAnalysisCV/example_images/trafficlight.jpg");
    Mat image_bgr = image.get_image();
    Mat image_hsv;
    //convert to hsv image
    cvtColor(image_bgr, image_hsv, COLOR_BGR2HSV);
    //slit channels
    Mat hsv[3];
    split(image_bgr, hsv);
    // imwrite("traffic_light_hsv.png", image_hsv);
    show("image", hsv[0]);
    return 0;
}