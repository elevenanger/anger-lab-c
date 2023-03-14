cmake_minimum_required(VERSION 3.23)
project(anger_lab_c C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(base)
include_directories(csapp)

ADD_SUBDIRECTORY(base)
ADD_SUBDIRECTORY(csapp)