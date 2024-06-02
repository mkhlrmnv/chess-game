cmake_minimum_required(VERSION 3.10)

# set the project name
project(Chess-Game)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)

# specify where the source files are
set(SOURCE_DIR src)

add_subdirectory(src)

set(SFML_SRC src/game.cpp)

set(BUILD_SHARED_LIBS false)

set(BUILD_SHARED_LIBS FALSE)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

set(CMAKE_BUILD_TYPE Debug) # this adds debug information and disables compiler optimizations

# add the executable
add_executable(Chess-Game ${SOURCE_DIR}/main.cpp ${SFML_SRC})
target_link_libraries(Chess-Game PRIVATE sfml-graphics sfml-window sfml-system)
target_link_libraries(Chess-Game PUBLIC src_code_library)