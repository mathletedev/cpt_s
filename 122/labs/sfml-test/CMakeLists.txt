cmake_minimum_required(VERSION 3.28)

project(sfml-test)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(EXEC main)

include_directories(includes)

file(GLOB SOURCES src/*.cpp)

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

add_executable(${EXEC} ${SOURCES})

target_link_libraries(${EXEC} sfml-graphics sfml-audio)
