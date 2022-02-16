cmake_minimum_required(VERSION 3.21)
project(DataStruct C)

set(CMAKE_C_STANDARD 99)

file (GLOB_RECURSE files *.cpp)
foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    add_executable (${exe} ${file} )
    message (\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()

add_executable(DataStruct main.c)

add_executable(LinearTable  LinearTable/main.c)

add_executable(SingleLinkedList  LinkedList/SingleLinkedList/main.c)

add_executable(DoubleLinkedList  LinkedList/DoubleLinkedList/main.c)