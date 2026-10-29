# Include all the files in the sakura engine directory.
target_sources(SakuraEngine PRIVATE

    # Sakura Engine root folder.
    SakuraEngine.h
    skrpch.h
    
    # Core Folder
    core/Application.cpp
    core/Application.h
    core/Core.h
    core/EntryPoint.h
    core/Types.h
    core/Window.h

    # Event Folder
    event/ApplicationEvent.h
    event/Event.h
    event/KeyEvent.h
    event/MouseEvent.h
    event/WindowEvent.h

    # Graphics Folder
    graphics/Shader.cpp
    graphics/Shader.h

    # ImGui Folder
    imgui/ImGuiLayer.cpp
    imgui/ImGuiLayer.h

    # Layer Folder
    layer/Layer.cpp
    layer/Layer.h
    layer/LayerStack.cpp
    layer/LayerStack.h

    # Logging Folder
    logging/Log.cpp
    logging/Log.h

    # Math Folder
    math/Vector2D.cpp
    math/Vector2D.h

    # Input Folder
    input/Input.h
)

# Check the platform and include necessary sources and preprocessor Definitions
if (WIN32)
    # Set the preprocessor definitions to contain windows plaform
    target_compile_definitions(SakuraEngine PRIVATE SKR_PLATFORM_WINDOWS GLFW_INCLUDE_NONE)

    # Set the target source to contain windows platform files
    target_sources(SakuraEngine PRIVATE 
        platform/Windows/WindowsWindow.cpp
        platform/Windows/WindowsWindow.h
        platform/Windows/WindowsInput.cpp
        platform/Windows/WindowsInput.h
    )
endif()

# Set the precompiled header
target_precompile_headers(SakuraEngine PRIVATE skrpch.h)