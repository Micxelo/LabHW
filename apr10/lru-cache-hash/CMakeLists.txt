cmake_minimum_required(VERSION 3.10)
project(lru_cache CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(lru_cache
	main.cpp
	lru.cpp
)
