cmake_minimum_required(VERSION 3.26)

project(inheritance)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(EXEC main)

include_directories(includes)

file(GLOB SOURCES src/*.cpp)

add_executable(${EXEC} ${SOURCES})
