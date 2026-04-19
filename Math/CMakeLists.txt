cmake_minimum_required(VERSION 3.22.1)
project(math)
add_library(${PROJECT_NAME} Vector2D.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})