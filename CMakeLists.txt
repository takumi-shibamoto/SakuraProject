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

add_executable(${PROJECT_NAME} main.cpp)

# Copy the assets file after building the executable
add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_CURRENT_SOURCE_DIR}/assets
    $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
)

# link all the libraries
target_link_libraries(${PROJECT_NAME} PRIVATE glfw glad math core engine)

# Set the visual studio debugger's working directory
set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_DEBUGGER_WORKING_DIRECTORY "$<TARGET_FILE_DIR:${PROJECT_NAME}>"
)