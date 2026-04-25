cmake_minimum_required(VERSION 3.22.1)
project(SakuraProject)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add the sub directories
add_subdirectory(math)
add_subdirectory(core)
add_subdirectory(engine)
add_subdirectory(extern)

file(GLOB_RECURSE SHADERS CONFIGURE_DEPENDS "assets/shaders/*")
add_executable(${PROJECT_NAME} main.cpp ${SHADERS})

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
)

# link all the libraries
target_link_libraries(${PROJECT_NAME} PRIVATE glfw glad math core engine)