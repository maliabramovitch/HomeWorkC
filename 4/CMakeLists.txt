cmake_minimum_required(VERSION 3.22)
project(4 C)

set(CMAKE_C_STANDARD 99)

add_executable(4 main.c Hist.c Hist.h LinkedList.c LinkedList.h test_hist.c test_hist.h)
