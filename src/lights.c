#include <stdint.h>
#include "lights.h"

double clamp(double value)
{
    double lowClamp = (value < 0.0) ? 0.0 : value;
    return (lowClamp > 1.0) ? 1.0 : lowClamp;
}

Color clampColor(Color color)
{
    return newColor(color.r, color.g, color.b);
}

uint32_t colorTo24Bit(Color color)
{
    uint32_t output = 0;
    int r, g, b;
    color = clampColor(color);
    r = (int) (color.r * 255);
    g = (int) (color.g * 255);
    b = (int) (color.b * 255);
    output += (uint32_t) r * 0x00010000;
    output += (uint32_t) g * 0x00000100;
    output += (uint32_t) b * 0x00000001;
    return output;
}

Color colorFrom24Bit(uint32_t color32)
{
    Color output = newColor(0, 0, 0);
    int r = color32 >> 16;
    int g = (color32 >> 8) - (r << 8);
    int b = color32 - (r << 16) - (g << 8);
    output.r = r / 256.0;
    output.g = g / 256.0;
    output.b = b / 256.0;
    return output;
}

LightNode newSun(Vector direction, Color color, double intensity)
{
    LightNode lightNode;
    lightNode.type = SUN;
    lightNode.light.sun.direction = vecNormal(direction);
    lightNode.light.sun.color = color;
    lightNode.light.sun.intensity = intensity;
    lightNode.next = NULL;
    return lightNode;
}

LightNode newPointLight(Vector position, Color color, double intensity)
{
    LightNode lightNode;
    lightNode.type = POINTLIGHT;
    lightNode.light.pointLight.position = position;
    lightNode.light.pointLight.color = color;
    lightNode.light.pointLight.intensity = intensity;
    lightNode.next = NULL;
    return lightNode;
}

Color newColor(double r, double g, double b)
{
    Color color;
    color.r = clamp(r);
    color.g = clamp(g);
    color.b = clamp(b);
    return color;
}

Color copyColor(Color color)
{
    return color;
}

Color colorSum(Color sum, Color color)
{
    sum.r = sum.r + color.r;
    sum.g = sum.g + color.g;
    sum.b = sum.b + color.b;
    return sum;
}

Color colorProd(Color product, Color color)
{
    product.r = product.r * color.r;
    product.g = product.g * color.g;
    product.b = product.b * color.b;
    return product;
}

Color colorMult(Color color, double multiplier)
{
    color.r = color.r * multiplier;
    color.g = color.g * multiplier;
    color.b = color.b * multiplier;
    return color;
}

double lightIntensity(LightNode *lightPtr)
{
    switch (lightPtr->type)
    {
        case SUN:
            return lightPtr->light.sun.intensity;
        case POINTLIGHT:
            return lightPtr->light.pointLight.intensity;
        default:
            return 0.0;
    }
}

Color lightColor(LightNode *lightPtr)
{
    switch (lightPtr->type)
    {
        case SUN:
            return lightPtr->light.sun.color;
        case POINTLIGHT:
            return lightPtr->light.pointLight.color;
        default:
            return newColor(0.0, 0.0, 0.0);
    }
}

Color colorFromLight(LightNode *lightPtr)
{
    return colorMult(lightColor(lightPtr), lightIntensity(lightPtr));
}
