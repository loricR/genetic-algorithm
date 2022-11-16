cmake_minimum_required(VERSION 3.23)
project(projet C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(projet
        Individu.h
        Individu.c
        Population.h
        Population.c
        main.c)