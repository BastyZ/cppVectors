//
// Created by bastyz on 10/13/18.
//

#ifndef CPPVECTORS_VECTOR_H
#define CPPVECTORS_VECTOR_H


#include <cmath>
#include "Point.h"
#include "Vertex.h"

template <class T>
class Vector {
private:
    Point<T> *dot;
public:
    Vector(Point<T> &p) {
        this->dot = &p;
    }

    Vector(Point<T> &base, Point<T> &edge) {
        this->dot = new Point<T> (edge - base);
    }

    Vector(T x, T y, T z) {
        this->dot = new Point<T>(x, y, z);
    }

    Point<T> *get() {
        return dot;
    }

    T getX() {
        return this->get()->getX();
    }

    T getY() {
        return this->get()->getY();
    }

    T getZ() {
        return this->get()->getZ();
    }

    static double module(Vector &a) {
        T first = std::pow(a.getX(),2);
        T second = std::pow(a.getY(),2);
        T third = std::pow(a.getZ(),2);
        return first + second + third;
    }

    static Vector<double> normalized(Vector<T> &a) {
        double m = module(a);
        Vector<double> result((double) a.getX()/m,(double) a.getY()/m,(double) a.getZ()/m);
        return result;
    }

    void normalize() {
        this->dot = normalized(*this)->get();
    }

    Vector<T> operator+(Vector<T> &b) {
        Point<T> result = *this->get()+*b.get();
        return Vector(result.getX(), result.getY(), result.getZ());
    }

    Vector<T> operator-(Vector<T> &b) {
        Point<T> result = *this->get() - *b.get();
        return Vector(result);
    }

    bool operator==(Vector<T> &b) {
        Point<double> *a = normalized(*this).get();
        Point<double> *c = normalized(b).get();
        return fabs(a->getX()-c->getX()) < 0.0001 &&
               fabs(a->getY()-c->getY()) < 0.0001 &&
               fabs(a->getZ()-c->getZ()) < 0.0001;
    }

    // Producto punto
    T operator*(Vector<T> &b) {
        T x = this->get()->getX() * b.get()->getX();
        T y = this->get()->getY() * b.get()->getY();
        T z = this->get()->getZ() * b.get()->getZ();
        return x + y + z;
    }

    Vector<T> cross(Vector<T> &b) {
        T x = this->getY()*b.getZ() - this->getZ()*b.getY();
        T y = this->getZ()*b.getX() - this->getX()*b.getZ();
        T z = this->getX()*b.getY() - this->getY()*b.getX();
        return Vector(x, y, z);
    }
};

#endif //CPPVECTORS_VECTOR_H
