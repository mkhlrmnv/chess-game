cmake_minimum_required(VERSION 3.10)

# set the project name
project(Chess-Game)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)

# specify where the source files are
set(SOURCE_DIR src)

add_subdirectory(src)

# add the executable
add_executable(Chess-Game ${SOURCE_DIR}/main.cpp)
target_link_libraries(Chess-Game PUBLIC src_code_library)