cmake_minimum_required(VERSION 3.27)
project(HW1_WORKSHEET)

set(CMAKE_CXX_STANDARD 17)

add_executable(HW1_WORKSHEET mtm_blockchain.cpp
        Transaction.h
        Utilities.h
        Utilities.cpp
        Transaction.cpp
        BlockChain.h
        BlockChain.cpp)
