cmake_minimum_required(VERSION 3.11) # FetchContent is available in 3.11+
project(rotating-polygons)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set this to the minimal version you want to support
find_package(raylib 3.0) # Let CMake search for a raylib-config.cmake

# This is the main part:

include_directories(${PROJECT_SOURCE_DIR})

add_executable(${PROJECT_NAME} main.cpp)
#set(raylib_VERBOSE 1)
target_link_libraries(${PROJECT_NAME} raylib)

# That's it! You should have an example executable that you can run. Have fun!
