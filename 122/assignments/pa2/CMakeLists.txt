cmake_minimum_required(VERSION 3.26)
project(pa2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(
        pa2
        commands.c
        commands.h
        globals.h
        linked_list.c
        linked_list.h
        main.c
        utils.c
        utils.h
)

add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy "../musicPlayList.csv" "./musicPlayList.csv"
)
