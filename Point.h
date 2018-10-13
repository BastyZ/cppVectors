//
// Created by bastyz on 10/13/18.
//

#ifndef CPPVECTORS_POINT_H
#define CPPVECTORS_POINT_H


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


#endif //CPPVECTORS_POINT_H
