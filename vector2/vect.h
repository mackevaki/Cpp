#include <iostream>
#include <cmath>
class Vector2 {
public:
    double x; double y;

    Vector2(double a, double b);
    Vector2();

    double getX() const;
    double getY() const;

    Vector2 operator+ (const Vector2 &other) const;
    Vector2 operator- (const Vector2 &other) const;
    Vector2 &operator+= (const Vector2 &other);

    Vector2 &operator-= (const Vector2 &other);
    Vector2 operator- () const;

    double operator* (const Vector2 &other);
    double operator^ (const Vector2 &other);

    Vector2 operator* (const double value) const;
    Vector2 operator/ (const double value) const;

    double squareLen() const;

    double  len() const;
    Vector2 norm() const;
    Vector2 perpendicular() const;
    Vector2 rotate (double alpha);
    Vector2 getRotated (double alpha) const;

    friend std::istream &operator>> (std::istream &stream, Vector2 &v);
    friend std::ostream &operator<< (std::ostream &stream, const Vector2 &v);
};