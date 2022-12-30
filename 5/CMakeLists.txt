cmake_minimum_required(VERSION 3.22)
project(5 C)

set(CMAKE_C_STANDARD 99)

add_executable(5 hex_dump.c compress8to7.c uncompress8to7.c cmake-build-debug/nimi.c)
