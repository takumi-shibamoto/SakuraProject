# Add glad as the static library
add_library(glad "glad/src/glad.c")

# Set the target include directories
target_include_directories(glad PUBLIC "glad/include")

# Link the libraries to the engine.
target_link_libraries(SakuraEngine PRIVATE glad)