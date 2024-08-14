set(SOURCES src/transforms.cpp
            include/transforms.h)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS} include/)

add_library(transforms ${SOURCES})
target_include_directories(transforms PUBLIC include/)
target_link_libraries(transforms ${OpenCV_LIBS})
