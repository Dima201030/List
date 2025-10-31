cmake_minimum_required(VERSION 3.16)

project(practicList LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(practicList main.cpp
    list.h list.cpp)

include(GNUInstallDirs)
install(TARGETS practicList
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
