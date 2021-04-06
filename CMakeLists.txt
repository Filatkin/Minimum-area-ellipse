cmake_minimum_required(VERSION 3.17)
project(Stars)

file(GLOB SOURCES "*.cpp")

add_executable(Stars ${SOURCES})
target_compile_features(Stars PRIVATE cxx_range_for)