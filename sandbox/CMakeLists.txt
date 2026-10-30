# add the sandbox executable
add_executable(Sandbox src/main.cpp)

# Set the macro that the application is on windows platform
target_compile_definitions(Sandbox PRIVATE SKR_PLATFORM_WINDOWS)

# Set the working directory to the current source directory.
set_target_properties(Sandbox PROPERTIES
    VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
)

# link all the libraries
target_link_libraries(Sandbox PRIVATE SakuraEngine)