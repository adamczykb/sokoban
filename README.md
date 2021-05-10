# CMakeLists

cmake_minimum_required(VERSION 3.17)
project(LLC-game)

set(CMAKE_CXX_STANDARD 14)

add_executable(LLC-game main.cpp)
target_link_libraries(LLC-game -lsfml-graphics -lsfml-window -lsfml-system)
