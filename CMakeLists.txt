cmake_minimum_required(VERSION 3.15)
project(pong VERSION 1.0 LANGUAGES CXX)

# Use C++17 (or higher if you prefer)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find raylib installed on your system
find_package(raylib REQUIRED)

# Add your executable
add_executable(pong
    src/main.cpp
)

# Link raylib and system libraries raylib needs
target_link_libraries(pong PRIVATE raylib)

# Optional: organize build output
set_target_properties(pong PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
