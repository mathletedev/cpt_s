cmake_minimum_required(VERSION 3.26)

project(pa7)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(EXEC main)

include_directories(includes)

file(GLOB SOURCES src/*.cpp)

add_executable(${EXEC} ${SOURCES})

add_custom_command(
	TARGET ${EXEC} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy "../data/classlist.csv" "./data/classlist.csv"
)
