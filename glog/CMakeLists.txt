CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
PROJECT(demo)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} /usr/lib/x86_64-linux-gnu/libglog.so)