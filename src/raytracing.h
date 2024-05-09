#ifndef RAYTRACING_H
#define RAYTRACING_H

#include "vectormath.h"
#include "lights.h"
#include "objects.h"
#include "intersections.h"

Color traceRay(const Ray, ObjectNode *, LightNode *, const Color, int);
Color sumOfLambertians(Ray, LightNode *, ObjectNode *);
Ray reflection(Ray, Ray);
Ray refraction(Ray, Ray, double, double);

#endif
