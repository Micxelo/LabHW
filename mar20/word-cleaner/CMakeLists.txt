cmake_minimum_required(VERSION 3.10)
project(word_cleaner C)

set(CMAKE_C_STANDARD 99)

add_executable(word_cleaner
	main.c
	utils.c
)
