cmake_minimum_required(VERSION 3.20)
project(RedroBurgerEngine VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(redro_burger
    src/main.cpp
    engine/core/Application.cpp
)

target_include_directories(redro_burger PRIVATE engine)
