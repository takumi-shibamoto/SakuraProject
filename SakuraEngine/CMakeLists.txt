# Find required packages that is packaged using vcpkg
find_package(spdlog CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)

# Create the SakuraEngine shared library
add_library(SakuraEngine SHARED)

# Include all the files in the sakura engine directory.
target_sources(SakuraEngine PRIVATE

    # Sakura Engine root folder.
    Application.cpp
    Application.h
    SakuraEngine.h
    skrpch.h
    Window.h

    # Core Folder
    core/Core.h
    core/EntryPoint.h
    core/Types.h

    # Event Folder
    event/ApplicationEvent.h
    event/Event.h
    event/KeyEvent.h
    event/MouseEvent.h
    event/WindowEvent.h

    # Graphics Folder
    graphics/Shader.cpp
    graphics/Shader.h

    # Logging Folder
    logging/Log.cpp
    logging/Log.h

    # Math Folder
    math/Vector2D.cpp
    math/Vector2D.h
)

# Set the preprocessor Definitions for the SakuraEngine target
target_compile_definitions(SakuraEngine PRIVATE SKR_BUILD_DLL $<$<CONFIG:DEBUG>:SKR_ENABLE_ASSERT>)

# Check the platform and include necessary sources and preprocessor Definitions
if (WIN32)
    # Set the preprocessor definitions to contain windows plaform
    target_compile_definitions(SakuraEngine PRIVATE SKR_PLATFORM_WINDOWS)

    # Set the target source to contain windows platform files
    target_sources(SakuraEngine PRIVATE 
        platform/Windows/WindowsWindow.cpp
        platform/Windows/WindowsWindow.h
    )
endif()

# Set the precompiled header
target_precompile_headers(SakuraEngine PRIVATE skrpch.h)

# Set the include directories and link libraries for the SakuraEngine target
target_include_directories(SakuraEngine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(SakuraEngine PUBLIC glfw glad::glad spdlog::spdlog)

# List all the source files in the SakuraEngine target for better organization in IDEs
get_target_property(ALL_ENGINE_SOURCES SakuraEngine SOURCES)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${ALL_ENGINE_SOURCES})