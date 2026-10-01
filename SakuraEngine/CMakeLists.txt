# Get all the source files in the current directory
file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS 
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
)

# Find required packages that is packaged using vcpkg
find_package(spdlog CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)

# Create the SakuraEngine shared library
add_library(SakuraEngine SHARED ${SOURCE_FILES})

# Add subdirectories for the engine modules
add_subdirectory(core)
add_subdirectory(event)
add_subdirectory(graphics)
add_subdirectory(math)
add_subdirectory(logging)

# Set the preprocessor Definitions for the SakuraEngine target
target_compile_definitions(SakuraEngine PRIVATE SKR_PLATFORM_WINDOWS SKR_BUILD_DLL)

# Set the include directories and link libraries for the SakuraEngine target
target_include_directories(SakuraEngine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(SakuraEngine PUBLIC glfw glad::glad spdlog::spdlog)

# List all the source files in the SakuraEngine target for better organization in IDEs
get_target_property(ALL_ENGINE_SOURCES SakuraEngine SOURCES)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${ALL_ENGINE_SOURCES})