cmake_minimum_required(VERSION 3.26)

project(lab9)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(EXEC main)

include_directories(includes)

file(GLOB SOURCES src/*.cpp)

add_executable(${EXEC} ${SOURCES})

add_custom_command(
	TARGET ${EXEC} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy "../data/input1.txt" "./data/input1.txt"
)
add_custom_command(
	TARGET ${EXEC} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy "../data/input2.txt" "./data/input2.txt"
)
add_custom_command(
	TARGET ${EXEC} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy "../data/input3.txt" "./data/input3.txt"
)
add_custom_command(
	TARGET ${EXEC} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy "../data/input4.txt" "./data/input4.txt"
)
