cmake_minimum_required(VERSION 3.10)
project(phone_booker C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(phone_booker
	main.c
	contact.c
)
