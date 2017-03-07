#include "vect.h"
#include <iostream>
#include <cmath>
#include <fstream>

Vector2::Vector2() : x(0), y(0) {}

Vector2::Vector2(double a, double b) : x(a), y(b) {}

double Vector2::getX() const { return x; }

double Vector2::getY() const { return y; }

Vector2 Vector2::operator+ (const Vector2 &other) const {
    return Vector2(x + other.x, y + other.y);
}

Vector2 &Vector2::operator+= (const Vector2 &other) {
    x += other.x;
    y += other.y;

    return *this;
}

Vector2 Vector2::operator- (const Vector2 &other) const {
    return Vector2(x - other.x, y - other.y);
}

Vector2 &Vector2::operator-= (const Vector2 &other) {
    x -= other.x;
    y -= other.y;

    return *this;
}

double Vector2::operator*(const Vector2 &other) {
    return x*other.x + y*other.y;
}

double Vector2::operator^(const Vector2 &other) {
    return x*other.y - y*other.x;
}

Vector2 Vector2::operator* (const double val) const {
    return Vector2(val*x, y*val);
}

Vector2 Vector2::operator/ (const double val) const {
    return Vector2(x/val, y/val);
}

Vector2 Vector2::norm(void) const {
    return Vector2(x/sqrt(x*x + y*y), y/sqrt(x*x + y*y));
}

Vector2 Vector2::perpendicular() const {
    return Vector2(y, -x);
}

double Vector2::len() const {
    return sqrt(x*x + y*y);
}

double Vector2::squareLen() const {
    return x*x + y*y;
}

Vector2 Vector2::operator-() const {
    return Vector2(-x, -y);
}

Vector2 Vector2::rotate(double alpha) {
    double ex_x = x;
    double ex_y = y;

    x = ex_x*cos(alpha) - ex_y*sin(alpha);
    y = ex_x*sin(alpha) + ex_y*cos(alpha);

    return Vector2(x, y);
}
Vector2 Vector2::getRotated(double alpha) const {
    return Vector2(x, y).rotate(alpha);
}

std::istream &operator>> (std::istream &stream, Vector2 &v) {
    stream >> v.x;
    stream >> v.y;

    return stream;
}

std::ostream &operator<< (std::ostream &stream, const Vector2 &v) {
    stream << "(" << v.x << ", " << v.y << ")";

    return stream;
}