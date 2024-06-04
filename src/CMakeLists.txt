# Add all your source files in this directory
file(GLOB_RECURSE GUI_SRC_FILES "gui/*.cpp")
file(GLOB_RECURSE CTRL_SRC_FILES "ctrl/*.cpp")

set(SRC_FILES
    ${GUI_SRC_FILES}
    ${CTRL_SRC_FILES}
)

# Create a library from the source files
add_library(src_code_library ${SRC_FILES})

# Add the "src" directory to the include directories for the library
target_include_directories(src_code_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})