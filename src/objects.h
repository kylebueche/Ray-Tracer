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
    Vector normal;
    Vector position;
    Color color;
    double roughness;
} Plane;

typedef struct
{
    double radius;
    Vector position;
    Color color;
    double roughness;
    double transparency;
    double focaldistance;
    double glossiness;
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
    struct objectNode *next;
} ObjectNode;

ObjectNode newPlane(Vector, Vector, Color, double);
ObjectNode newSphere(Vector, double, Color, double, double transparency, double focaldistance, double glossiness);

Vector objectPosition(ObjectNode *);
Vector objectNormal(ObjectNode *, Vector);
Color objectColor(ObjectNode *);
double objectRoughness(ObjectNode *);

#endif
