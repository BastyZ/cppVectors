cmake_minimum_required(VERSION 3.12)
project(cppVectors)

set(CMAKE_CXX_STANDARD 17)

add_executable(cppVectors main.cpp main.h Point.cpp Point.h HalfEdge.cpp HalfEdge.h Vertex.cpp Vertex.h Face.cpp Face.h Vector.cpp Vector.h)