cmake_minimum_required(VERSION 3.24.3)
project(heatmap LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(BUILD_TESTING OFF)
# set(CMAKE_BUILD_TYPE Debug)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(heatmap src/main.cpp)

target_link_libraries(heatmap ${OpenCV_LIBS})