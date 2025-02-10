cmake_minimum_required(VERSION 3.10)
project(ExampleUndistort)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# find_package(OpenCV REQUIRED)
find_package(Undistort REQUIRED)

# include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(example example.cpp)

# target_include_directories(example PRIVATE ${OpenCV_INCLUDE_DIRS})
# target_link_libraries(example PRIVATE ${OpenCV_LIBS} Undistort::undistort)
target_link_libraries(example PRIVATE Undistort::undistort)
