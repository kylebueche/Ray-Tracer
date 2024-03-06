#include "raytracing.h"
#include <stdio.h>

Color traceRay(const Ray ray, ObjectNode *objects, LightNode *lights, const Color skybox, int numberOfReflections)
{
    Color outputColor = skybox;
    Color color = { 0 };
    double roughness;
    Intersection intersection = findClosestObject(ray, objects);
    Ray normalRay = { 0 };
    if (numberOfReflections > 0)
    {
        numberOfReflections--;
        if (intersection.distance > 0.0)
        {
            normalRay.position = vecsAdd(ray.position, vecMult(ray.direction, intersection.distance));
            normalRay.direction = objectNormal(intersection.objectPtr, normalRay.position);
            color = objectColor(intersection.objectPtr);
            roughness = objectRoughness(intersection.objectPtr);
            outputColor = colorProd(color, colorSum(colorMult(sumOfLambertians(normalRay, lights, objects), roughness),
                                                          colorMult(traceRay(
                                                                            reflection(ray, normalRay),
                                                                            objects,
                                                                            lights,
                                                                            skybox,
                                                                            numberOfReflections
                                                                            ), (1.0 - roughness))));
            return outputColor;
        }
        else
        {
            numberOfReflections = 0;
            return skybox;
        }
    }
    else
    {
        return newColor(0.0, 0.0, 0.0);
    }
}

Color sumOfLambertians(Ray normalRay, LightNode *lights, ObjectNode *objects)
{
    Color incomingColor = newColor(0.0, 0.0, 0.0);
    Intersection closest;
    double lightDistance;
    Ray rayToLight;
    rayToLight.position = normalRay.position;
    while (lights != NULL)
    {
        switch (lights->type)
        {
            case SUN:
                rayToLight.direction = lights->light.sun.direction;
                closest = findClosestObject(rayToLight, objects);
                if (closest.distance <= 0.0)
                {
                    incomingColor = colorSum(incomingColor, colorMult(colorFromLight(lights), vecDot(rayToLight.direction, normalRay.direction)));
                }
                break;
            case POINTLIGHT:
                rayToLight.direction = vecsSub(lights->light.pointLight.position, rayToLight.position);
                lightDistance = vecLen(rayToLight.direction);
                vecNormalize(&rayToLight.direction);
                closest = findClosestObject(rayToLight, objects);
                if (closest.distance <= 0.0 || closest.distance > lightDistance)
                {
                    incomingColor = colorSum(incomingColor, colorMult(colorFromLight(lights), vecDot(rayToLight.direction, normalRay.direction)));
                }
                break;
        }
        lights = lights->next;
    }
    return incomingColor;
}

/** normal is facing OUT from the surface **/

Ray reflection(Ray incoming, Ray normal)
{
    Ray reflected;
    incoming.direction = vecsSub(normal.position, incoming.position);
    reflected.position = normal.position;
    reflected.direction = vecsSub(vecMult(vecsAdd(vecMult(normal.direction, vecDot(vecNeg(incoming.direction), normal.direction)), incoming.direction), 2), incoming.direction);
    return reflected;
}