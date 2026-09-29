cmake_minimum_required(VERSION 3.20)

project(GravitySim
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(gravity_sim
    src/main.cpp
    src/Gravity.cpp
)

target_include_directories(gravity_sim
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)