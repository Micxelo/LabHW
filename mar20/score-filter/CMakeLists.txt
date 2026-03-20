cmake_minimum_required(VERSION 3.10)
project(score_filter CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(score_filter
	main.cpp
	matrix.cpp
)
