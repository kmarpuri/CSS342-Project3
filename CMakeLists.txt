cmake_minimum_required(VERSION 4.0)
project(CSS342_Project3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(main
        main.cpp
        list342.h)

add_executable(children
        children.cpp
        child.h
        child.cpp
        children.txt)


configure_file(children.txt children.txt COPYONLY)
configure_file(main.txt main.txt COPYONLY)