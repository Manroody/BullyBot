cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(BullyBot)
file(GLOB project_SRCS src/*.cpp)

add_executable(BullyBot ${project_SRCS})
# add_executable(BullyBot src/main.cpp)
