cmake_minimum_required(VERSION 3.5)
project(Calculator)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_BUILD_TYPE Debug)

set(SOURCE_FILES src/main.cpp src/infix2postfix.cpp src/infix2postfix.h src/postfixeval.cpp src/postfixeval.h src/calculator.cpp src/calculator.h)
add_executable(Calculator ${SOURCE_FILES})
