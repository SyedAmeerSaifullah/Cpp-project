cmake_minimum_required(VERSION 3.29)
project(untitled)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}")
add_executable(untitled pmain.cpp
        tickets.h
        tickets.cpp
        ticketsmain.cpp
        supplies.cpp
        supplies.h
        trains.cpp
        trains.h
        function.h
        staffmanagementfunction.cpp
        staffmanagementfunction.h
        passengers.h
        passengers.cpp)