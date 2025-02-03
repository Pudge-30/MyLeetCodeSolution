# This the the code for solving the problems in the https://leetcode.cn/problems

# The minimize version required
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

 # https://cmake.org/cmake/help/latest/prop_tgt/CXX_STANDARD.html
 set(CMAKE_CXX_STANDARD 17)
 set(CMAKE_CXX_STANDARD_REQUIRED ON)
 set(CMAKE_CXX_EXTENSIONS OFF)
 
# Modified the problem index eachtime.
project(LeetCodeProblem_459)

# Set user sources.
# Put all the xxx.cpp files in SRC
file(GLOB SRC "${PROJECT_SOURCE_DIR}/*.cpp")
# Generate executable program.
add_executable(${PROJECT_NAME} ${SRC})

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})