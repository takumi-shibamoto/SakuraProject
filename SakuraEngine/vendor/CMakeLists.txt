# add the external libraries as subdirectories
add_subdirectory(glad)
add_subdirectory(imgui)

# Link the libraries to the engine.
target_link_libraries(SakuraEngine PRIVATE glad ImGui)