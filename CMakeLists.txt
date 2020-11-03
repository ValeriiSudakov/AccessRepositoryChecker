cmake_minimum_required(VERSION 3.17)
project(src/DirectoryAccessChecker)

include_directories(src)

file(GLOB_RECURSE src_cpp "src/*.cpp")
file(GLOB_RECURSE src_h "src/*.h")

set(CMAKE_CXX_STANDARD 17)

add_executable(DirectoryAccessChecker ${src_cpp} ${src_h} main.cpp )

target_link_libraries(DirectoryAccessChecker ${src_cpp} ${src_h})