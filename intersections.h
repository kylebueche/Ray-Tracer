#ifndef INTERSECTIONS_H
#define INTERSECTIONS_H

#include "vectormath.h"

typedef struct
{
    Vector point;
    Vector direction;
} Ray;

typedef struct
{
    Vector point;
    Vector normal;
} Plane;

double intersectsPlane(Ray, Plane);

#endif
