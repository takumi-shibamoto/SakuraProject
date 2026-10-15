# Add glad as the static library
add_library(glad STATIC

    "src/glad.c"
    "include/glad/glad.h"
    "include/KHR/khrplatform.h"

)

# Set the target include directories
target_include_directories(glad PUBLIC "glad/include")