#include <iostream>
#include <opencv2/opencv.hpp>
#include "camera_params.h"

bool CameraParams::load(const std::string &filename, cv::Mat &camera_matrix, cv::Mat &dist_coeffs, cv::Size &image_size)
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

    int width = 0;
    int height = 0;
    fs["image_width"] >> width;
    fs["image_height"] >> height;

    if (width <= 0 || height <= 0)
    {
        std::cerr << "Invalid image size in file: " << filename << std::endl;
        return false;
    }

    image_size = cv::Size(width, height);

    std::cout << "Loaded camera parameters from: " << filename << std::endl;
    return true;
}