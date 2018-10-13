//
// Created by bastyz on 10/13/18.
//

#ifndef CPPVECTORS_VERTEX_H
#define CPPVECTORS_VERTEX_H


#include "Point.h"

template <class T>
class HalfEdge;

template <class T>
class Vertex {
private:
    Point<T> *point;
    HalfEdge<T> *hEdge;
public:
    Vertex(Point<T> *p) {
        point = p;
    }

    Vertex(Point<T> *p, HalfEdge<T> *e) {
        point = p;
        hEdge = e;
    }

    void addHalfEdge(HalfEdge<T> *e) {
        hEdge = e;
    }

    void operator=(Vertex<T> &ver) {
        point = ver.point;
        hEdge = ver.hEdge;
    }

    void operator=(Vertex<T> *ver) {
        point = &ver->point;
        hEdge = &ver->hEdge;
    }
};


#endif //CPPVECTORS_VERTEX_H
