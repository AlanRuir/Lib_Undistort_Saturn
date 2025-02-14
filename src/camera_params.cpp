#include <iostream>
#include <opencv2/opencv.hpp>
#include "camera_params.h"

bool CameraParams::load(const std::string &filename, cv::Mat &camera_matrix, cv::Mat &dist_coeffs)
{
    std::cout << "param path: " << filename << std::endl;

    cv::FileStorage fs(filename, cv::FileStorage::READ);

    if (!fs.isOpened())
    {
        std::cerr << "Failed to open camera parameters file: " << filename << std::endl;
        return false;
    }

    fs["camera_matrix"] >> camera_matrix;
    fs["distortion_coefficients"] >> dist_coeffs;

    if (camera_matrix.empty() || dist_coeffs.empty())
    {
        std::cerr << "Invalid camera parameters in file: " << filename << std::endl;
        return false;
    }

    std::cout << "Loaded camera parameters from: " << filename << std::endl;
    return true;
}