cmake_minimum_required(VERSION 3.30)
project(password_manager)

set(CMAKE_CXX_STANDARD 17)

# Add global include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add the executable target
add_executable(password_manager main.cpp src/ui.cpp)

# Add include directories to your target
target_include_directories(password_manager
        PRIVATE ${CMAKE_SOURCE_DIR}/include
)