#ifndef __CAMERA_PARAMS_H__
#define __CAMERA_PARAMS_H__

#include <opencv2/opencv.hpp>
#include <string>

class CameraParams
{
public:
    static bool load(const std::string &filename, cv::Mat &camera_matrix, cv::Mat &dist_coeffs);
};

#endif // __CAMERA_PARAMS_H__