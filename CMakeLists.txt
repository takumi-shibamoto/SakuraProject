cmake_minimum_required(VERSION 3.22.1)
project(SakuraProject)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add the sub directories
add_subdirectory(SakuraEngine)
add_subdirectory(extern)


file(GLOB_RECURSE SHADERS CONFIGURE_DEPENDS "assets/shaders/*")
add_executable(Application main.cpp ${SHADERS})

# Set the macro that the application is on windows platform
target_compile_definitions(Application PRIVATE SKR_PLATFORM_WINDOWS)

set_target_properties(Application PROPERTIES
    VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
)

# link all the libraries
target_link_libraries(Application PRIVATE glfw glad SakuraEngine)