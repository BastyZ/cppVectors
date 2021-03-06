//
// Created by bastyz on 10/13/18.
//

#ifndef CPPVECTORS_HALFEDGE_H
#define CPPVECTORS_HALFEDGE_H

#include "Point.h"
#include "Vertex.h"
#include "Face.h"

template <class T>
class HalfEdge {
private:
    Vertex<T> *vertex;
    Face<T> *face;
    HalfEdge<T> *next, *previous;
    HalfEdge<T> *pair;
public:
    HalfEdge(Vertex<T> *vertex1) {
        this->vertex = vertex1;
    }

    HalfEdge(Vertex<T> *vertex1, HalfEdge<T> *prev) {
        this->vertex = vertex1;
        this->previous = prev;
    }

    HalfEdge(Vertex<T> *vertex1, HalfEdge<T> *prev, HalfEdge<T> *sig) {
        this->vertex = vertex1;
        this->previous = prev;
        this->next = sig;
    }

    void setFace(Face<T> *f) {
        face = f;
    }

    void setNext(HalfEdge<T> *sig) {
        this->next = sig;
    }

    void setPrev(HalfEdge<T> *prev) {
        this->previous = prev;
    }

    void setPair(HalfEdge<T> *p) {
        this->pair = p;
    }

    Face<T> getFace() {
        return this->face;
    }
};

#endif //CPPVECTORS_HALFEDGE_H
