cmake_minimum_required(VERSION 4.0)
project(CSS342_Project3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CSS342_Project3
        child.cpp
        child.h
        list342.h
        main.cpp)

configure_file(children.txt children.txt COPYONLY)
configure_file(main.txt main.txt COPYONLY)