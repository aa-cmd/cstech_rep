cmake_minimum_required(VERSION 2.8)

project(Chess_Demo)

set(PROJECT_DIR ${CMAKE_SOURCE_DIR})

set(PROJECT_INCLUDE_DIR ${PROJECT_DIR}/include)

set(PROJECT_SOURCE_DIR ${PROJECT_DIR}/src)

set( PROJECT_SOURCES
        ${PROJECT_SOURCE_DIR}/main.cpp
        ${PROJECT_SOURCE_DIR}/chess.cpp)

set( PROJECT_HEADERS
        ${PROJECT_INCLUDE_DIR}/config.h
        ${PROJECT_INCLUDE_DIR}/chess.h)

set(CMAKE_C_FLAGS_DEBUG "-g -DDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "-g -DDEBUG")

include_directories(${PROJECT_INCLUDE_DIR})

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})