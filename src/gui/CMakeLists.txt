# Add all your source files in this directory
set(GUI_FILES
    game.cpp
    render.cpp
)

# Create a library from the source files
add_library(gui_code_library ${GUI_FILES})

# Add the "src" directory to the include directories for the library
target_include_directories(gui_code_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})