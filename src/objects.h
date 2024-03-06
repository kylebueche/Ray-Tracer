#ifndef OBJECTS_H
#define OBJECTS_H

#include "vectormath.h"
#include "lights.h"

typedef enum
{
    PLANE,
    SPHERE
} ObjectType;

typedef struct
{
    Vector point;
    Vector normal;
    Color color;
} Plane;

typedef struct
{
    Vector point;
    double radius;
    Color color;
} Sphere;
 
typedef union
{
    Plane plane;
    Sphere sphere;
} Object;

typedef struct
{
    Object object;
    ObjectType type;
    ObjectNode *next;
} ObjectNode;

ObjectNode newPlane(Vector point, Vector normal, Color color)
ObjectNode newSphere(Vector point, double radius, Color color)
#endif
