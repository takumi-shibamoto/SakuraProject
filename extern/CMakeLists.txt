include(FetchContent)

# Fetch the glfw library from GitHub
FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG        3.4
)
FetchContent_MakeAvailable(glfw)

# Add glad as a library
add_library(glad ${CMAKE_CURRENT_SOURCE_DIR}/glad/src/glad.c)
target_include_directories(glad PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/glad/include)