#include <iostream>
#include <chrono>
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
    auto start = std::chrono::high_resolution_clock::now();
    cv::Mat undistorted_image = undistorter.processFrame(input_image);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Undistortion took " << elapsed.count() << " seconds." << std::endl;

    // 显示结果
    cv::imshow("Original Image", input_image);
    cv::imshow("Undistorted Image", undistorted_image);
    cv::waitKey(0);

    return 0;
}
