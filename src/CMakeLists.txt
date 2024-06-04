# Add all your source files in this directory
set(SRC_FILES
    level.cpp
    square.cpp
    piece.cpp
    game.cpp
    render.cpp
)

# Create a library from the source files
add_library(src_code_library ${SRC_FILES})

# Add the "src" directory to the include directories for the library
target_include_directories(src_code_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})