cmake_minimum_required(VERSION 3.10)
project(TE2_AnalisisAlgoritmos)

set(CMAKE_CXX_STANDARD 14)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)
include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})
add_definitions(${GTKMM_CFLAGS_OTHER})
set(SOURCES
        main.cpp
        BubbleSort.cpp
        SelectionSort.cpp
        MergeSort.cpp
        AllSortedLinkedListSearch.cpp
        BSTInsert.cpp
        Graphics.cpp
)

add_executable(TE2_AnalisisAlgoritmos ${SOURCES})
target_link_libraries(TE2_AnalisisAlgoritmos ${GTKMM_LIBRARIES} sigc-2.0 glibmm-2.4)
