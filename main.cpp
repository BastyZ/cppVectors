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

void test_dcel() {
    Point<double> a(1,1,1), b(2,1,1), c(2,2,1), d(1,2,1);
    Vertex<double> v1(&a), v2(&b), v3(&c), v4(&d);
    HalfEdge<double> edge1(&v4);
    v4.addHalfEdge(&edge1);
    Face<double> face1(&edge1);
    assert(face1.notNull()); //Face no nulo
    edge1.setFace(&face1); //cara que lo contiene
    HalfEdge<double> edge2(&v1, &edge1);
    v1.addHalfEdge(&edge2);
    edge1.setNext(&edge2);
    edge2.setFace(&face1);
    HalfEdge<double> edge3(&v3, &edge2, &edge1);
    v3.addHalfEdge(&edge3);
    edge3.setFace(&face1);
    HalfEdge<double> edge4(&v1);
    Face<double> face2(&edge4);
    edge4.setFace(&face2);
    HalfEdge<double> edge5(&v2, &edge4);
    v2.addHalfEdge(&edge5);
    edge4.setNext(&edge5);
    edge5.setFace(&face2);
    HalfEdge<double> edge6(&v3, &edge5);
    edge6.setFace(&face2);
    edge6.setPair(&edge2);
    edge2.setPair(&edge6);
    edge5.setNext(&edge6);
}

int main() {
    test_point();
    test_vector();
    test_dcel();
    std::cout << "All test passed" << std::endl;
    return 0;
}