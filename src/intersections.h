#ifndef INTERSECTIONS_H
#define INTERSECTIONS_H

#include "vectormath.h"
#include "objects.h"

typedef struct
{
    Object *objectPtr;
    double distance;
} Intersection;

typedef struct
{
    Vector point;
    Vector direction;
} Ray;

Ray reflection(Ray, Ray);
double intersectsPlane(Ray, Plane);
double intersectsSphere(Ray, Sphere);

#endif
