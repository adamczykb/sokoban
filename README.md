# CMakeLists Bartek
```makefile
cmake_minimum_required(VERSION 3.17)
project(LLC-game)

set(CMAKE_CXX_STANDARD 14)

add_executable(LLC-game main.cpp activities/filehandling.cpp activities/filehandling.h activities/worldrender.cpp activities/worldrender.h activities/homescreen.cpp activities/homescreen.h activities/movement.cpp activities/movement.h)
target_link_libraries(LLC-game -lsfml-graphics -lsfml-window -lsfml-system)
```
# CMakeLists Paweł
```makefile
cmake_minimum_required(VERSION 3.17)
project(LLC-game)

set(CMAKE_CXX_STANDARD 14)

set(SFML_DIR "C:/Program Files/mingw-w64/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(LLC-game main.cpp activities/filehandling.cpp activities/filehandling.h activities/worldrender.cpp activities/worldrender.h activities/homescreen.cpp activities/homescreen.h activities/movement.cpp activities/movement.h)
target_link_libraries(LLC-game sfml-graphics sfml-audio)
```