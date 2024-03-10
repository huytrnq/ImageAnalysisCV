# cmake_minimum_required(VERSION 3.24)
# project(image_utils LANGUAGES CXX)

# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_FILES 
    src/image.cpp 
    src/video.cpp 
    include/video.h
    include/image.h)
# add_library(image_utils src/video.cpp)

# # add_executable(image_utils ${SOURCE_FILES})
# target_link_libraries(image_utils ${OpenCV_LIBS})
# target_include_directories(image_utils INTERFACE include/)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS} include/)

add_library(image_utils ${SOURCE_FILES})

target_include_directories(image_utils PUBLIC include/)

target_link_libraries(image_utils ${OpenCV_LIBS})