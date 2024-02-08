cmake_minimum_required(VERSION 3.27)
project(AddressBook)

set(CMAKE_CXX_STANDARD 17)

add_executable(AddressBook main.cpp
        Contact.h
        Contact.cpp
        Functions.h
        Functions.cpp)
