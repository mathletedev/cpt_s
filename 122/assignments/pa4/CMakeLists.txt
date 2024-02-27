cmake_minimum_required(VERSION 3.26)
project(pa4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(pa4
        fitnessappwrapper.cpp
        fitnessappwrapper.hpp
        main.cpp
        plan.cpp
        plan.hpp
        utils.cpp
        utils.hpp
)

add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy "../dietPlans.txt" "./dietPlans.txt"
)

add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy "../exercisePlans.txt" "./exercisePlans.txt"
)

