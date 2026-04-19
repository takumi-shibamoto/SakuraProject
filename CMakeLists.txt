cmake_minimum_required(VERSION 3.22.1)
project(SakuraProject)
add_executable(${PROJECT_NAME} main.cpp)

target_link_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/Math)
target_link_libraries(${PROJECT_NAME} Math)

target_link_directories(${PROJECT_NAME} INTERFACE ${CMAKE_SOURCE_DIR}/Core)
target_link_libraries(${PROJECT_NAME} Core)