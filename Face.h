//
// Created by bastyz on 10/13/18.
//

#ifndef CPPVECTORS_FACE_H
#define CPPVECTORS_FACE_H

template <class T>
class HalfEdge;

template <class T>
class Face {
private:
    HalfEdge<T> *edge;
public:
    Face(HalfEdge<T> *anEdge) {
        this->edge = anEdge;
    }
};


#endif //CPPVECTORS_FACE_H
