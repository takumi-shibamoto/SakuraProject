add_library(SakuraEngine SHARED)

add_subdirectory(graphics)
add_subdirectory(math)
add_subdirectory(core)

target_include_directories(SakuraEngine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(SakuraEngine PRIVATE glad glfw)