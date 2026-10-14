# Add glad as the static library
add_library(glad STATIC

    "glad/src/glad.c"
    "glad/include/glad/glad.h"
    "glad/include/KHR/khrplatform.h"

)

# Set the target include directories
target_include_directories(glad PUBLIC "glad/include")

# Link the libraries to the engine.
target_link_libraries(SakuraEngine PRIVATE glad)