cmake_minimum_required(VERSION 3.10)
project(phone_booker C)

set(CMAKE_C_STANDARD 99)

add_executable(phone_booker
	main.c
	contact.c
)
