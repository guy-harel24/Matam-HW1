cmake_minimum_required(VERSION 3.27)
project(HW1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(HW1
        BlockChain.cpp
        BlockChain.h
        main.cpp
        Transaction.cpp
        Transaction.h
        Utilities.cpp
        Utilities.h)
