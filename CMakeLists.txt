cmake_minimum_required(VERSION 3.6)
project(sdizo_1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp lista.cpp lista.h menu.cpp menu.h tablica.cpp tablica.h binaryheap.cpp binaryheap.h)
add_executable(sdizo_1 ${SOURCE_FILES})