cmake_minimum_required(VERSION 3.22)
project(Saper C)

set(CMAKE_C_STANDARD 99)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(Include)

add_executable(Saper main.c Include/dataJSON.h Source/dataJSON.c Source/window.c Include/window.h)

target_link_libraries(Saper -ljson-c -lglut)
