cmake_minimum_required(VERSION 3.10)
project(myapp)
set(CMAKE_C_STANDARD 99)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 头文件目录
include_directories(include)

# 源文件
set(SOURCES
	src/main.c
	src/utils.c
)

add_executable(${PROJECT_NAME} ${SOURCES})
