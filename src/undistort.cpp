#include "undistort.h"
#include "camera_params.h"

Undistort::Undistort(const std::string &camera_params_path)
{
    CameraParams::load(camera_params_path, camera_matrix_, dist_coeffs_);
}

cv::Mat Undistort::processFrame(const cv::Mat &frame)
{
    cv::Mat undistorted_frame;

    // 获取图像尺寸
    cv::Size imageSize = frame.size();

    // 创建映射矩阵
    cv::Mat map1, map2;
    cv::fisheye::initUndistortRectifyMap(camera_matrix_, dist_coeffs_, cv::Mat(), camera_matrix_, imageSize, CV_16SC2, map1, map2);

    // 使用映射矩阵进行去畸变
    cv::remap(frame, undistorted_frame, map1, map2, cv::INTER_LINEAR);

    return undistorted_frame;
}
