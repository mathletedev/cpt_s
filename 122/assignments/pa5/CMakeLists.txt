cmake_minimum_required(VERSION 3.26)
project(pa5)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(
        pa5
        data.cpp
        data.hpp
        main.cpp
        queue.cpp
        queue.hpp
        queuenode.cpp
        queuenode.hpp
        simulation.cpp
        simulation.hpp
        tests.cpp
        tests.hpp
)
