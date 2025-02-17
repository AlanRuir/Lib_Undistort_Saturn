#ifndef __UNDISTORT_H__
#define __UNDISTORT_H__

#include <opencv2/opencv.hpp>

class Undistort
{
public:
    Undistort(const std::string &camera_params_path);
    cv::Mat processFrame(const cv::Mat &frame);

private:
    cv::Mat camera_matrix_;
    cv::Mat dist_coeffs_;
    cv::Mat map_x_;
    cv::Mat map_y_;
    cv::Size image_size_;
};

#endif // __UNDISTORT_H__