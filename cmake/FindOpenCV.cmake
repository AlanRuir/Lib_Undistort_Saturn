# 查找 OpenCV
find_package(PkgConfig REQUIRED)
pkg_check_modules(OpenCV REQUIRED opencv4)

if (OpenCV_FOUND)
    message(STATUS "Found OpenCV: ${OpenCV_LIBRARIES}")
else()
    message(FATAL_ERROR "OpenCV not found!")
endif()
