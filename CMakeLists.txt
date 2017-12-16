cmake_minimum_required(VERSION 3.7)
project(ZMPO3_HOME)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Book.cpp Book.h utils/CharUtils.cpp utils/CharUtils.h utils/SortUtils.cpp utils/SortUtils.h utils/Comparator.cpp utils/Comparator.h)
add_executable(ZMPO3_HOME ${SOURCE_FILES})