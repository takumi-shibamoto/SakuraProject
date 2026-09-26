add_library(graphics Shader.cpp Shader.h)
target_include_directories(graphics PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(graphics PRIVATE glad glfw)