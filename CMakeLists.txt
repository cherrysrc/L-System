cmake_minimum_required(VERSION 3.17)
project(LSystem)

file (GLOB CPP_FILES src/*.c)
file (GLOB H_FILES src/*.h)
set (SOURCE_FILES ${CPP_FILES} ${H_FILES})

add_executable(LSystem ${SOURCE_FILES} main.c)
target_link_libraries(LSystem m)
