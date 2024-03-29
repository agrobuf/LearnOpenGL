cmake_minimum_required(VERSION 3.22)
set(TOP_PROJECT_NAME CreatingAWindow)
project(${TOP_PROJECT_NAME} LANGUAGES CXX)

# Set project properties
# SET(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
message("Building with CMake version: ${CMAKE_VERSION}")

# Set CMake output locations
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Set the toolchain generated by conan
set(CMAKE_TOOLCHAIN_FILE "../Environment/build/Release/generators/conan_toolchain.cmake")

# Find packages
find_package(glfw3 REQUIRED)

# Add sub directories
add_subdirectory(../Dependencies/glad ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
add_subdirectory(Source)

# Link libraries
target_link_libraries(${TOP_PROJECT_NAME} glfw)
