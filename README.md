# CMakeLists Bartek

cmake_minimum_required(VERSION 3.17)
project(LLC-game)

set(CMAKE_CXX_STANDARD 14)

add_executable(LLC-game main.cpp)
target_link_libraries(LLC-game -lsfml-graphics -lsfml-window -lsfml-system)

# CMakeLists Paweł

cmake_minimum_required(VERSION 3.17)
project(LLC-game)

set(CMAKE_CXX_STANDARD 14)

set(SFML_DIR "C:/Program Files/mingw-w64/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(LLC-game main.cpp)
target_link_libraries(LLC-game sfml-graphics sfml-audio)
