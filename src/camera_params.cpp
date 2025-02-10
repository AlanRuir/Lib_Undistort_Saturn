#include "camera_params.h"
#include <iostream>

bool CameraParams::load(const std::string &filename, cv::Mat &camera_matrix, cv::Mat &dist_coeffs)
{
    std::cout << __LINE__ << std::endl;

    std::cout << "param path: " << filename << std::endl;

    cv::FileStorage fs(filename, cv::FileStorage::READ);

    std::cout << __LINE__ << std::endl;

    if (!fs.isOpened())
    {
        std::cerr << "Failed to open camera parameters file: " << filename << std::endl;
        return false;
    }

    std::cout << __LINE__ << std::endl;

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