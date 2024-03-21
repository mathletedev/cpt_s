cmake_minimum_required(VERSION 3.26)

project(pa6)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(EXEC main)

include_directories(includes)

file(GLOB SOURCES src/*.cpp)

add_executable(${EXEC} ${SOURCES})

add_custom_command(
	TARGET ${EXEC} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy "../data/MorseTable.txt" "./data/MorseTable.txt"
)
add_custom_command(
	TARGET ${EXEC} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy "../data/InverseMorseTable.txt" "./data/InverseMorseTable.txt"
)
add_custom_command(
	TARGET ${EXEC} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy "../data/Convert.txt" "./data/Convert.txt"
)
add_custom_command(
	TARGET ${EXEC} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy "../data/InverseConvert.txt" "./data/InverseConvert.txt"
)
