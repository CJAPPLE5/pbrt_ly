//
// Created by W on 2023/3/18.
//

#ifndef PBRT_PBRT_H
#define PBRT_PBRT_H

#include <assert.h>
#include <istream>
#include <ostream>
#include "cmath"


#ifdef PBRT_FLOAT_AS_DOUBLE
typedef double Float;
#else
typedef float Float;

template <typename T>
class Point2;
template <typename T>
class Point3;
template <typename T>
class Vector2;
template <typename T>
class Vector3;
#endif //PBRT_PBRT_H
