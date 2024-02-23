#ifndef VECTORMATH_H
#define VECTORMATH_H

#include "mymath.h"

typedef struct
{
    double x, y, z;
} Vector;

typedef Vector Point;

void vecAdd(Vector *, const Vector);
void vecSub(Vector *, const Vector);
void vecMult(Vector *, double);
void vecDiv(Vector *, double);
Vector vecNeg(const Vector);
Vector vecsAdd(const Vector, const Vector);
Vector vecsSub(const Vector, const Vector);
Vector vecsMult(const Vector, const Vector);
Vector vecsDiv(const Vector, const Vector);
double vecLenSqr(const Vector);
double vecLen(const Vector);
double vecNormalize(Vector *);
double vecDot(const Vector, const Vector);
Vector vecCross(const Vector, const Vector);

#endif
