#ifndef LIGHTS_H
#define LIGHTS_H

#include <stddef.h>
#include <stdint.h>
#include "vectormath.h"

typedef enum lightType
{
    SUN,
    POINTLIGHT
} LightType;

typedef struct color
{
    double r;
    double g;
    double b;
} Color;

typedef struct pointLight
{
    Color color;
    double intensity;
    Vector position;
} PointLight;

typedef struct sun
{
    Color color;
    double intensity;
    Vector direction;
} Sun;

typedef union light
{
    Sun sun;
    PointLight pointLight;
} Light;

typedef struct lightNode
{
    Light light;
    LightType type;
    struct lightNode *next;
} LightNode;

LightNode newSun(Vector, Color, double);
LightNode newPointLight(Vector, Color, double);
Color newColor(double, double, double);
Color copyColor(Color);
Color colorSum(Color, Color);
Color colorProd(Color, Color);
Color colorMult(Color, double);
Color colorFromLight(LightNode *);
Color lightColor(LightNode *);
double lightIntensity(LightNode *);
Color clampColor(Color);
double clamp(double);
uint32_t colorTo24Bit(Color);
#endif
