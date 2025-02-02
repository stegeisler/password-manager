cmake_minimum_required(VERSION 3.16)
project(password_manager)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add global include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add the executable target
add_executable(password_manager main.cpp src/ui.cpp)

# Add include directories to your target
target_include_directories(password_manager
        PRIVATE ${CMAKE_SOURCE_DIR}/include
)

# Fetch GoogleTest
# FetchContent is a CMake module that downloads and integrates external dependencies
include(FetchContent)
# FetchContent_Declare tells CMake to download GoogleTest from the provided URL
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
# Prevent GoogleTest from overriding compiler options,
# forces GoogleTest to use the same runtime library as this project,
# prevents conflicts, especially on Windows (MSVC), where different runtime libraries
# (static/dynamic) might cause linking errors
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Fetch, build and make GoogleTest available
FetchContent_MakeAvailable(googletest)

# Creates an executable named test_ui that runs tests
add_executable(test_ui tests/test_ui.cpp src/ui.cpp)

# Link test executable with GoogleTest and the project,
# links test_ui with gtest_main, which provides the main() function for running tests,
# PRIVATE means gtest_main is only used internally in test_ui
target_link_libraries(test_ui PRIVATE gtest_main)

# Enable testing and add the test to CTest, running ctest will now execute test_ui
enable_testing()
add_test(NAME TestUI COMMAND test_ui)
