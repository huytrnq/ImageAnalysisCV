cmake_minimum_required(VERSION 3.28.0)
project(intensity_transforms LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS} include/)

add_subdirectory(transforms)

add_executable(intensity_transforms main.cpp)
target_link_libraries(intensity_transforms transforms ${OpenCV_LIBS})

