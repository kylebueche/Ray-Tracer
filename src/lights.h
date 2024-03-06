#ifndef LIGHTS_H
#define LIGHTS_H

#include "vectormath.h"

typedef enum
{
    SUN
    POINTLIGHT
} LightType;

typedef struct
{
    double r;
    double g;
    double b;
} Color;

typedef struct
{
    Color color;
    double intensity;
    Vector position;
} PointLight;

typedef struct
{
    Color color;
    double intensity;
    Vector direction;
} Sun;

typedef union
{
    Sun sun;
    PointLight pointLight;
} Light;

typedef struct
{
    Light light;
    LightType type;
    LightNode *next;
} LightNode;

Color sumOfLambertians(Color, Ray, LightNode, ObjectNode);
Color newColor(double, double, double);
Color copyColor(Color, Color);
Color colorSum(Color, Color);
Color colorProd(Color, Color);
Color colorMult(Color, double);
Color colorFromLight(LightNode, double);
double clamp(double);

#endif
