cmake_minimum_required(VERSION 3.15)
project(pong VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(raylib REQUIRED)

add_executable(pong
    src/main.cpp
    src/ball.cpp
    src/paddle.cpp
)

target_link_libraries(pong PRIVATE raylib)

set_target_properties(pong PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
