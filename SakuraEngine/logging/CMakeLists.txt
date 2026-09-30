file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS 
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
)

target_sources(SakuraEngine PRIVATE ${SOURCE_FILES})
target_include_directories(SakuraEngine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})