#ifndef RAYTRACING_H
#define RAYTRACING_H

#include "vectormath.h"
#include "lights.h"
#include "objects.h"

Color traceRay(Ray ray, ObjectNode *objects, LightNode *lights, Color skybox, int numberOfReflections)
Ray reflection(Ray, Ray);

#endif
