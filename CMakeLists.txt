cmake_minimum_required(VERSION 3.29)
project(TE2_AnalisisAlgoritmos)

set(CMAKE_CXX_STANDARD 20)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)
include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})
add_definitions(${GTKMM_CFLAGS_OTHER})
add_executable(Graphics main.cpp Graphics.cpp)
target_link_libraries(Graphics ${GTKMM_LIBRARIES})

add_executable(TE2_AnalisisAlgoritmos main.cpp
        BubbleSort.cpp
        BSTInsert.cpp
        AllSortedLInkedListSearch.cpp
        Graphics.cpp
        MergeSort.cpp
        SelectionSort.cpp)
