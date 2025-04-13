cmake_minimum_required(VERSION 3.30)

project(modern_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)


add_executable(clock_1 "clock/clock_1.cpp")
add_executable(clock_2 "clock/clock_2.cpp")

add_executable(rvalue_1 "rvalue/rvalue_1.cpp")




