#include <iostream>
#include <cmath>
#include <cassert>

template <class T>
class Point {
private:
    T x;
    T y;
    T z;
public:
    Point (T xPoint, T yPoint, T zPoint) {
        x = xPoint;
        y = yPoint;
        z = zPoint;
    }

    T getX() {
        return x;
    }

    T getY() {
        return y;
    }

    T getZ() {
        return z;
    }

    void setX(T val) {
        this->x = val;
    }

    void setY(T val) {
        this->y = val;
    }

    void setZ(T val) {
        this->z = val;
    }

    void set(T x_val, T y_val, T z_val) {
        this->setX(x_val);
        this->setY(y_val);
        this->setZ(z_val);
    }

    Point<T> operator+(Point<T> &b) {
        return Point(this->x + b.getX(), this->y + b.getY(), this->z + b.getZ());
    }

    Point<T> operator-(Point<T> &b) {
        return Point(this->x - b.getX(), this->y - b.getY(), this->z - b.getZ());
    }

    bool operator==(Point<T> &b) {
        bool boolean = fabs(this->x - b.getX())< 0.0001
                       && fabs(this->y - b.getY())< 0.0001
                       && fabs(this->z - b.getZ())< 0.0001;
        return boolean;
    }


};

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

void test_point() {
    Point<int> a(2,4,2);
    Point<int> b(3,1,2);
    int n = (a+b).getZ();
    assert(n == 4);
    n = (b-a).getX();
    assert(n == 1);
    bool m = a == b;
    assert(!m);
}

void test_vector() {
    Vector<double> a(2.5, 1.1, 3);
    Vector<double> b(5.5, 0.1, 4.5);
    double n = (b+a).getY();
    assert(fabs(n-1.2)<0.01);
    n = (b-a).getX();
    assert(n == 3);
    Vector<int> i(1,1,1);
    assert(i*i == 3);
    bool c = i==i;
    assert(c);
    std::cout << b.cross(a).getY() << std::endl;
    assert(abs(b.cross(a).getY()+5.25) < 0.01);
}

int main() {
    test_point();
    test_vector();
    std::cout << "All test passed" << std::endl;
    return 0;
}