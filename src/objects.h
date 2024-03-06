#ifndef OBJECTS_H
#define OBJECTS_H

#include "vectormath.h"
#include "lights.h"

typedef enum objectType
{
    PLANE,
    SPHERE
} ObjectType;

typedef struct plane
{
    Vector normal;
    Vector position;
    Color color;
    double roughness;
} Plane;

typedef struct sphere
{
    double radius;
    Vector position;
    Color color;
    double roughness;
} Sphere;
 
typedef union object
{
    Plane plane;
    Sphere sphere;
} Object;

typedef struct objectNode
{
    Object object;
    ObjectType type;
    struct objectNode *next;
} ObjectNode;

ObjectNode newPlane(Vector, Vector, Color, double);
ObjectNode newSphere(Vector, double, Color, double);

Vector objectPosition(ObjectNode *);
Vector objectNormal(ObjectNode *, Vector);
Color objectColor(ObjectNode *);
double objectRoughness(ObjectNode *);

#endif
