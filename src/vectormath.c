#include "vectormath.h"
#include "mymath.h"
#include <stdio.h>
extern Vector newVector(const double x, const double y, const double z);
/*{
    Vector v;
    v.x = x;
    v.y = y;
    v.z = z;
    return v;
}*/

extern void vecAdd(Vector *a, const Vector b);
/*{
    a->x += b.x;
    a->y += b.y;
    a->z += b.z;
}*/

extern void vecSub(Vector *a, const Vector b);
/*{
    a->x -= b.x;
    a->y -= b.y;
    a->z -= b.z;
}*/

extern Vector vecMult(Vector a, const double b);
/*{
    a.x *= b;
    a.y *= b;
    a.z *= b;
    return a;
}*/

extern Vector vecDiv(Vector a, const double b);
/*{
    a.x /= b;
    a.y /= b;
    a.z /= b;
    return a;
}*/

extern Vector vecNeg(Vector a);
/*{
    a.x *= -1.0;
    a.y *= -1.0;
    a.z *= -1.0;
    return a;
}*/

extern Vector vecsAdd(Vector a, const Vector b);
/*{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    return a;
}*/

extern Vector vecsSub(Vector a, const Vector b);
/*{
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    return a;
}*/

extern Vector vecsMult(Vector a, const Vector b);
/*{
    a.x *= b.x;
    a.y *= b.y;
    a.z *= b.z;
    return a;
}*/

extern Vector vecsDiv(Vector a, const Vector b);
/*{
    a.x /= b.x;
    a.y /= b.y;
    a.z /= b.z;
    return a;
}*/

extern double vecLenSqr(const Vector a);
/*{
    return sqr(a.x) + sqr(a.y) + sqr(a.z);
}*/

extern double vecLen(const Vector a);
/*{
    return sqrt(vecLenSqr(a));
}*/

extern double vecNormalize(Vector *a);
/*{
    double b = vecLen(*a);
    *a = vecDiv(*a, b);
    return b;
}*/

extern Vector vecNormal(Vector a);
/*{
    return vecDiv(a, vecLen(a));
}*/

extern double vecDot(const Vector a, const Vector b);
/*{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}*/

/**
Vector vecCross(const Vector a, const Vector b)
{
    return (Vector) { (a.y * b.z - a.z * b.y), (a.z * b.x - a.x * b.z), (a.x * b.y - a.y * b.x) };
}**/
