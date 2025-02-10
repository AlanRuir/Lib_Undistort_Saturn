#include <iostream>
#include <opencv2/opencv.hpp>
#include "camera_params.h"
#include "undistort.h"

int main()
{
    std::string param_file = "../examples/camera_params.yml"; // 相机参数文件

    // 读取测试图像
    std::string image_path = "../examples/test_image.jpg";
    cv::Mat input_image = cv::imread(image_path);
    if (input_image.empty())
    {
        std::cerr << "Failed to load image: " << image_path << std::endl;
        return -1;
    }

    // 进行去畸变处理
    Undistort undistorter(param_file);
    cv::Mat undistorted_image = undistorter.processFrame(input_image);

    // 显示结果
    cv::imshow("Original Image", input_image);
    cv::imshow("Undistorted Image", undistorted_image);
    cv::waitKey(0);

    return 0;
}
