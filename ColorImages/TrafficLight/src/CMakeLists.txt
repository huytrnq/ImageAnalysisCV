set(SOURCE_FILES main.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

add_subdirectory(../../../ImageUtils ${CMAKE_BINARY_DIR}/ImageUtils)

# target_include_directories(${PROJECT_NAME} PUBLIC ImageUtils)
# target_link_directories(${PROJECT_NAME} PRIVATE ImageUtils)
target_link_libraries(${PROJECT_NAME} image_utils)

