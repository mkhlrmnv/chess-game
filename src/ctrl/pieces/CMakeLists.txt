# Add all your source files in this directory
set(PIECE_FILES
    pawn.cpp
    horse.cpp
    bishop.cpp
    rook.cpp
    queen.cpp
    king.cpp
)

# Create a library from the source files
add_library(piece_code_library ${PIECE_FILES})

# Add the "src" directory to the include directories for the library
target_include_directories(piece_code_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})