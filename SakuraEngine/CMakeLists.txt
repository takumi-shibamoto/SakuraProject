file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS 
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
)

add_library(SakuraEngine SHARED ${SOURCE_FILES})

add_subdirectory(graphics)
add_subdirectory(math)
add_subdirectory(core)

target_compile_definitions(SakuraEngine PRIVATE SKR_PLATFORM_WINDOWS SKR_BUILD_DLL)

target_include_directories(SakuraEngine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(SakuraEngine PRIVATE glad glfw)

get_target_property(ALL_ENGINE_SOURCES SakuraEngine SOURCES)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${ALL_ENGINE_SOURCES})