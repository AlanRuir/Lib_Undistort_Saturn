#include "undistort.h"
#include "camera_params.h"

Undistort::Undistort(const std::string &camera_params_path)
{
    CameraParams::load(camera_params_path, camera_matrix_, dist_coeffs_, image_size_);

    // 创建映射矩阵
    cv::fisheye::initUndistortRectifyMap(camera_matrix_, dist_coeffs_, cv::Mat(), camera_matrix_, image_size_, CV_16SC2, map_x_, map_y_);
}

cv::Mat Undistort::processFrame(const cv::Mat &frame)
{
    cv::Mat undistorted_frame;

    // 使用映射矩阵进行去畸变
    cv::remap(frame, undistorted_frame, map_x_, map_y_, cv::INTER_LINEAR);

    return undistorted_frame;
}
