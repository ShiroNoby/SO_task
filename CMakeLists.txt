cmake_minimum_required( VERSION 3.1)
project(parse)

add_subdirectory(sort)

add_executable(parse parse.cpp)

target_link_libraries(parse sort)
