cmake_minimum_required(VERSION 3.26)
project(Cramer_s_Rule)

set(CMAKE_CXX_STANDARD 17)

add_executable(Cramer_s_Rule main.cpp
        Matrix.cpp
        Matrix.h)
