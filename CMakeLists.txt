cmake_minimum_required(VERSION 3.24)
project(RedroBurgerEngine VERSION 0.3.1 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CTest)

add_library(redro_core INTERFACE)
target_include_directories(redro_core INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/engine)

add_library(redro_game STATIC engine/game/BurgerGame.cpp)
target_link_libraries(redro_game PUBLIC redro_core)

if(BUILD_TESTING)
    add_executable(redro_core_tests tests/core_tests.cpp)
    target_link_libraries(redro_core_tests PRIVATE redro_game redro_core)
    add_test(NAME redro_core_tests COMMAND redro_core_tests)
endif()

include(FetchContent)
set(SDL_SHARED OFF CACHE BOOL "" FORCE)
set(SDL_STATIC ON CACHE BOOL "" FORCE)
set(SDL_TEST_LIBRARY OFF CACHE BOOL "" FORCE)
set(SDL_TESTS OFF CACHE BOOL "" FORCE)
set(SDL_EXAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_Declare(
    SDL3
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG release-3.2.10
    GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(SDL3)

add_executable(redro_burger src/main.cpp)
target_link_libraries(redro_burger PRIVATE redro_game SDL3::SDL3-static)
