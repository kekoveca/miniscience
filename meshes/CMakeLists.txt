cmake_minimum_required(VERSION 3.11)

set(CMAKE_CXX_FLAGS "-std=c++11 -g")

project(meshes)
add_executable(task0part1 task0part1.cpp)
add_executable(task0part2 task0part2.cpp)
add_executable(task0part3 task0part3.cpp)
add_executable(task1  task1.cpp)
add_executable(task2  task2.cpp)

# gmsh укажем явно (потому что он был просто распакован руками)
add_library(gmsh SHARED IMPORTED)
set_target_properties(gmsh PROPERTIES
    IMPORTED_LOCATION "/Users/kekoveca/gmsh-4.12.2-MacOSARM-sdk/lib/libgmsh.dylib"
    INTERFACE_INCLUDE_DIRECTORIES "/Users/kekoveca/gmsh-4.12.2-MacOSARM-sdk/include"
)
set(GMSH_LIBRARY gmsh)

# Укажем библиотеки для линковки
target_link_libraries(task0part1 ${GMSH_LIBRARY})
target_link_libraries(task0part2 ${GMSH_LIBRARY})
target_link_libraries(task0part3 ${GMSH_LIBRARY})
target_link_libraries(task1  ${GMSH_LIBRARY})
target_link_libraries(task2  ${GMSH_LIBRARY})