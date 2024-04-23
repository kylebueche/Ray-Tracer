#ifndef VECTORMATH_H
#define VECTORMATH_H

#include "vectormath.h"
#include "mymath.h"
#include <stdio.h>

typedef struct vector
{
    double x, y, z;
} Vector;
/*
void vecAdd(Vector *a, const Vector b);
void vecSub(Vector *a, const Vector b);
Vector vecMult(Vector a, double b);
Vector vecDiv(Vector a, double b);
Vector vecNeg(const Vector a);
Vector vecsAdd(const Vector a, const Vector b);
Vector vecsSub(const Vector a, const Vector b);
Vector vecsMult(const Vector a, const Vector b);
Vector vecsDiv(const Vector a, const Vector b);
double vecLenSqr(const Vector a);
double vecLen(const Vector a);
double vecNormalize(Vector *a);
Vector vecNormal(Vector a);
double vecDot(const Vector a, const Vector);
Vector vecCross(const Vector a, const Vector);
Vector newVector(const double x, const double y, const double z);
*/
inline Vector newVector(const double x, const double y, const double z)
{
    Vector v;
    v.x = x;
    v.y = y;
    v.z = z;
    return v;
}

inline void vecAdd(Vector *a, const Vector b)
{
    a->x += b.x;
    a->y += b.y;
    a->z += b.z;
}

inline void vecSub(Vector *a, const Vector b)
{
    a->x -= b.x;
    a->y -= b.y;
    a->z -= b.z;
}

inline Vector vecMult(Vector a, const double b)
{
    a.x *= b;
    a.y *= b;
    a.z *= b;
    return a;
}

inline Vector vecDiv(Vector a, const double b)
{
    a.x /= b;
    a.y /= b;
    a.z /= b;
    return a;
}

inline Vector vecNeg(Vector a)
{
    a.x *= -1.0;
    a.y *= -1.0;
    a.z *= -1.0;
    return a;
}

inline Vector vecsAdd(Vector a, const Vector b)
{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    return a;
}

inline Vector vecsSub(Vector a, const Vector b)
{
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    return a;
}

inline Vector vecsMult(Vector a, const Vector b)
{
    a.x *= b.x;
    a.y *= b.y;
    a.z *= b.z;
    return a;
}

inline Vector vecsDiv(Vector a, const Vector b)
{
    a.x /= b.x;
    a.y /= b.y;
    a.z /= b.z;
    return a;
}

inline double vecLenSqr(const Vector a)
{
    return sqr(a.x) + sqr(a.y) + sqr(a.z);
}

inline double vecLen(const Vector a)
{
    return sqrt(vecLenSqr(a));
}

inline double vecNormalize(Vector *a)
{
    double b = vecLen(*a);
    *a = vecDiv(*a, b);
    return b;
}

inline Vector vecNormal(Vector a)
{
    return vecDiv(a, vecLen(a));
}

inline double vecDot(const Vector a, const Vector b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

#endif
