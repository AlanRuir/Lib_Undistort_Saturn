cmake_minimum_required(VERSION 3.10)
project(UndistortLib)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 生成动态库
add_library(undistort SHARED
    src/undistort.cpp
    src/camera_params.cpp
)

# 头文件目录
target_include_directories(undistort PUBLIC include)

# 链接 OpenCV
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(undistort PRIVATE ${OpenCV_LIBS})

# 示例程序
add_executable(example examples/example.cpp)
target_link_libraries(example PRIVATE undistort ${OpenCV_LIBS})

# 测试
# enable_testing()
# add_executable(test_undistort test/test_undistort.cpp)
# target_link_libraries(test_undistort PRIVATE undistort)
# add_test(NAME UndistortTest COMMAND test_undistort)
