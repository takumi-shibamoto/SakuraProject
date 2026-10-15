# Find required packages that is packaged using vcpkg
find_package(spdlog CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

# Create the SakuraEngine shared library
add_library(SakuraEngine SHARED)

# Add the vendor subdirectory
add_subdirectory(vendor)

# Add the src subdirectory
add_subdirectory(src)

# Set the preprocessor Definitions for the SakuraEngine target
target_compile_definitions(SakuraEngine PRIVATE SKR_BUILD_DLL $<$<CONFIG:DEBUG>:SKR_ENABLE_ASSERT>)

# Set the include directories and link libraries for the SakuraEngine target
target_include_directories(SakuraEngine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(SakuraEngine PUBLIC glfw spdlog::spdlog)

# List all the source files in the SakuraEngine target for better organization in IDEs
get_target_property(ALL_ENGINE_SOURCES SakuraEngine SOURCES)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${ALL_ENGINE_SOURCES})