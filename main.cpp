#include <iostream>

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

    Point<T> operator+(Point<T> b) {
        return Point(this->x + b.getX(), this->y + b.getY(), this->z + b.getZ());
    }

    Point<T> operator-(Point<T> b) {
        return Point(this->x - b.getX(), this->y - b.getY(), this->z - b.getZ());
    }

    Point& operator=(Point<T> b) {
        this->set(b.getX(), b. getY(), b.getZ());
    }

    bool operator==(Point<T> b) {
        return this->x == b.getX() && this->y == b.getY() && this->z == b.getZ();
    }
};

int main() {
    Point<int> dot(2,1,1);
    dot.set(8,5,5);
    Point<int> dot2 = dot+dot;
    std::cout << dot2.getX() << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}