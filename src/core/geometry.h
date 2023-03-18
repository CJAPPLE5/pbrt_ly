//
// Created by W on 2023/3/18.
//

#ifndef PBRT_GEOMETRY_H
#define PBRT_GEOMETRY_H

#include "pbrt.h"

template <typename  T>
inline bool isNaN(const T x) {
    return std::isnan(x);
}

template <typename  T> class Vector2{
public:
    T x,y;
    Vector2() {x=y=0;}
    Vector2(T xx, T yy): x(xx), y(yy) {
        assert(HasNaNs());
    }

    bool HasNaNs() const {
        return std::isnan(x) || std::isnan(y);
    }

#ifndef NDEBUG
    Vector2(const Vector2<T> &v) {
        assert(!v.HasNaNs());
        x = v.x; y = v.y;
    }
    Vector2<T> &operator=(const Vector2<T>&v) {
        assert(!v.HasNaNs());
        x = v.x; y = v.y;
        return *this;
    }
#endif
    friend std::ostream & operator<<(std::ostream& os, const Vector2<T> &v) {
        os << "[" << v.x << ", " << v.y << "]";
        return os;
    }

    Vector2<T> operator+(const Vector2<T>&v) const {
        assert(!v.HasNaNs());
        return Vector2(x+v.x,y+v.y);
    }

    Vector2<T>& operator+=(const Vector2<T>&v)  {
        assert(!v.HasNaNs());
        x += v.x; y+=v.y;
        return *this;
    }

    Vector2<T> operator-(const Vector2<T> &v) const {
        assert(!v.HasNaNs());
        return Vector2(x-v.x, y-v.y);
    }

    Vector2<T>& operator-=(const Vector2<T>&v)  {
        assert(!v.HasNaNs());
        x -= v.x; y-=v.y;
        return *this;
    }

    bool operator==(const Vector2<T> &v) const{
        return x == v.x && y == v.y;
    }

    bool operator!=(const Vector2<T> &v) const {
        return x != v.x || y != v.y;
    }

    Vector2<T> operator*(T f) const {
        return Vector2<T>(x*f,y*f);
    }

    Vector2<T>& operator*=(T f) {
        assert(!std::isnan(f));
        x *= f; y*=f;
        return *this;
    }

    Vector2<T> operator/(T f) const {
        assert(f != 0);
        return Vector2<T>(x/f, y/f);
    }

    Vector2<T>& operator/=(T f) {
        assert(f != 0);
        x /=f; y/=f;
        return *this;
    }

    Vector2<T> operator-() const {
        return Vector2(-x,-y);
    }

    T operator[](int i) const {
        assert(i >= 0 && i <= 1);
        if(i == 0) return x;
        else return y;
    }

    T &operator[](int i) {
        assert(i >= 0 && i <= 1);
        if(i ==0 ) return x;
        else return y;
    }

    Float LengthSquared() const {return x*x + y * y;}
    Float Length() const {
        return std::sqrt((LengthSquared()));
    }
};

template <typename  T>
class  Point2{
public:
    T x,y;
    explicit Point2(const Point3<T> &p) : x(p.x), y(p.y) { assert(!HasNaNs());};
    Point2() {x = y =0;}
    Point2(T xx, T yy) : x(xx), y(yy) { assert(!HasNaNs());}


    bool HasNaNs() const {
        return isNaN(x) || isNaN(y);
    }
};


template <typename T>
class Point3{
    T x,y,z;
    Point3() {x=y=z=0;}
};


#endif //PBRT_GEOMETRY_H
