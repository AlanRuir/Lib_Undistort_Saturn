#include "undistort.h"
#include "camera_params.h"

Undistort::Undistort(const std::string &camera_params_path)
{
    std::cout << __LINE__ << std::endl;
    CameraParams::load(camera_params_path, camera_matrix_, dist_coeffs_);
    std::cout << __LINE__ << std::endl;
}

cv::Mat Undistort::processFrame(const cv::Mat &frame)
{
    cv::Mat undistorted_frame;
    cv::undistort(frame, undistorted_frame, camera_matrix_, dist_coeffs_);
    return undistorted_frame;
}
