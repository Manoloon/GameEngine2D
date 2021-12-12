cmake_minimum_required(VERSION 3.21)
project(GameEngine2D)

set(CMAKE_CXX_STANDARD 20)

add_executable(GameEngine2D main.cpp GESource/Math/FVec2.h)
