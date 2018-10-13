#include <iostream>
#include <cmath>
#include <cassert>

#include "Point.h"
#include "Vector.h"
#include "HalfEdge.h"

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
    assert(fabs(b.cross(a).getY()+5.25) < 0.01);
}

int main() {
    test_point();
    test_vector();
    Point<double> a(1,1,1);
    Vertex<double> vertex(&a);
    HalfEdge<double> edge(&vertex);
    Face<double> face(&edge);
    std::cout << "All test passed" << std::endl;
    return 0;
}