#ifndef VECTORMATH_H
#define VECTORMATH_H

#include "mymath.h"

typedef struct vector
{
    double x, y, z;
} Vector;

void vecAdd(Vector *, const Vector);
void vecSub(Vector *, const Vector);
Vector vecMult(Vector, double);
Vector vecDiv(Vector, double);
Vector vecNeg(const Vector);
Vector vecsAdd(const Vector, const Vector);
Vector vecsSub(const Vector, const Vector);
Vector vecsMult(const Vector, const Vector);
Vector vecsDiv(const Vector, const Vector);
double vecLenSqr(const Vector);
double vecLen(const Vector);
double vecNormalize(Vector *);
Vector vecNormal(Vector);
double vecDot(const Vector, const Vector);
Vector vecCross(const Vector, const Vector);
Vector newVector(double, double, double);

#endif
