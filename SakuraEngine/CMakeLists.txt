add_library(SakuraEngine INTERFACE)

add_subdirectory(graphics)
add_subdirectory(math)
add_subdirectory(core)

target_link_libraries(SakuraEngine INTERFACE graphics math core)
target_include_directories(SakuraEngine INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})