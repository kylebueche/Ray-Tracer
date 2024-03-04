#include "vectormath.h"
#include "mymath.h"
#include <stdio.h>

void vecAdd(Vector *a, const Vector b)
{
    a->x += b.x;
    a->y += b.y;
    a->z += b.z;
}

void vecSub(Vector *a, const Vector b)
{
    a->x -= b.x;
    a->y -= b.y;
    a->z -= b.z;
}

void vecMult(Vector *a, double b)
{
    a->x *= b;
    a->y *= b;
    a->z *= b;
}

void vecDiv(Vector *a, double b)
{
    a->x /= b;
    a->y /= b;
    a->z /= b;
}

Vector vecNeg(Vector a)
{
    a.x *= -1.0;
    a.y *= -1.0;
    a.z *= -1.0;
    return a;
}

Vector vecsAdd(Vector a, const Vector b)
{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    return a;
}

Vector vecsSub(Vector a, const Vector b)
{
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    return a;
}

Vector vecsMult(Vector a, const Vector b)
{
    a.x *= b.x;
    a.y *= b.y;
    a.z *= b.z;
    return a;
}

Vector vecsDiv(Vector a, const Vector b)
{
    a.x /= b.x;
    a.y /= b.y;
    a.z /= b.z;
    return a;
}

double vecLenSqr(const Vector a)
{
    return sqr(a.x) + sqr(a.y) + sqr(a.z);
}

double vecLen(const Vector a)
{
    return sqrt(vecLenSqr(a));
}

double vecNormalize(Vector *a)
{
    double b = vecLen(*a);
    vecDiv(a, b);
    return b;
}

double vecDot(const Vector a, const Vector b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
/**
Vector vecCross(const Vector a, const Vector b)
{
    return (Vector) { (a.y * b.z - a.z * b.y), (a.z * b.x - a.x * b.z), (a.x * b.y - a.y * b.x) };
}**/
