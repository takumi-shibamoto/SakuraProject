cmake_minimum_required(VERSION 3.22.1)

set(VCPKG_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/extern/vcpkg")

# Set the toolchain file for vcpkg if it exists and is not already defined
if (EXISTS "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "Vcpkg toolchain file")
endif()

# Bootstrap vcpkg if it hasn't been bootstrapped yet
if (EXISTS "${VCPKG_ROOT}" AND NOT EXISTS "${VCPKG_ROOT}/vcpkg.exe" AND WIN32)
    execute_process(COMMAND "${VCPKG_ROOT}/bootstrap-vcpkg.bat" "-disableMetrics" RESULT_VARIABLE VCPKG_BOOTSTRAP_RESULT)
endif()

# Turn on the vcpkg manifest mode if the vcpkg.json file exists
if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg.json")
    set(VCPKG_MANIFEST_MODE ON)
    set(VCPKG_MANIFEST_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
endif()

project(SakuraProject)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# External Libraries Configuration
include(GNUInstallDirs)

set(EXTERNAL_INCLUDES "")

# Add the sub directories
add_subdirectory(SakuraEngine)

file(GLOB_RECURSE SHADERS CONFIGURE_DEPENDS "assets/shaders/*")
add_executable(Application main.cpp ${SHADERS})

# Set the macro that the application is on windows platform
target_compile_definitions(Application PRIVATE SKR_PLATFORM_WINDOWS)

set_target_properties(Application PROPERTIES
    VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
)

# link all the libraries
target_link_libraries(Application PRIVATE SakuraEngine)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Application)