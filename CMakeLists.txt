cmake_minimum_required(VERSION 3.22.1)
project(SakuraProject)

include(FetchContent)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add the sub directories
add_subdirectory(math)
add_subdirectory(core)

# Fetch the glfw library from GitHub
FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG        3.4
)
FetchContent_MakeAvailable(glfw)

# Add glad as a library
add_library(glad ${CMAKE_SOURCE_DIR}/extern/glad/src/glad.c)
target_include_directories(glad PUBLIC ${CMAKE_SOURCE_DIR}/extern/glad/include)

add_executable(${PROJECT_NAME} main.cpp)

# link all the libraries
target_link_libraries(${PROJECT_NAME} PRIVATE glfw glad math core)