cmake_minimum_required(VERSION 3.5)
project(Calculator)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_BUILD_TYPE Debug)

set(SOURCE_FILES main.cpp infix2postfix.cpp infix2postfix.h postfixeval.cpp postfixeval.h calculator.cpp calculator.h)
add_executable(Calculator ${SOURCE_FILES})
