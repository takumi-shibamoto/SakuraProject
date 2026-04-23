add_library(engine INTERFACE)
add_subdirectory(graphics)
target_link_libraries(engine INTERFACE graphics)
target_include_directories(engine INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})