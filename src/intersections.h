#ifndef INTERSECTIONS_H
#define INTERSECTIONS_H

#include "vectormath.h"
#include "lights.h"
#include "objects.h"

typedef struct intersection
{
    ObjectNode *objectPtr;
    double distance;
} Intersection;

typedef struct
{
    Vector position;
    Vector direction;
} Ray;

Ray reflection(Ray, Ray);
Intersection findClosestObject(Ray, ObjectNode *);
double intersectsObject(Ray, ObjectNode *);
double intersectsPlane(Ray, Plane);
double intersectsSphere(Ray, Sphere);

#endif
