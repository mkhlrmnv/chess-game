file(GLOB_RECURSE PIECE_SRC_FILES "pieces/*.cpp")

# Add all your source files in this directory
set(CTRL_FILES
    level.cpp
    square.cpp
    piece.cpp
    ${PIECE_SRC_FILES}
)

# Create a library from the source files
add_library(ctrl_code_library ${CTRL_FILES})

# Add the "src" directory to the include directories for the library
target_include_directories(ctrl_code_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})