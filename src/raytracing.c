#include "raytracing.h"
#include <stdio.h>
#include <stdlib.h>
#define NORMALMARCH 0.0001

Color traceRay(const Ray ray, ObjectNode *objects, LightNode *lights, const Color skybox, int numberOfReflections)
{
    Color outputColor = skybox;
    Color color = { 0 };
    double roughness;
    double transparency;
    double refractiveIndex;
    Intersection intersection = findClosestObject(ray, objects);
    Ray normalRay = { 0 };
    Color lambertianContribution;
    Color reflectiveContribution;
    Color refractiveContribution;
    if (numberOfReflections > 0)
    {
        numberOfReflections--;
        if (intersection.distance > 0.0)
        {
            normalRay.position = vecsAdd(ray.position, vecMult(ray.direction, intersection.distance));
            normalRay.direction = objectNormal(intersection.objectPtr, normalRay.position);
            normalRay.position = vecsAdd(normalRay.position, vecMult(normalRay.direction, NORMALMARCH));
            color = objectColor(intersection.objectPtr);
            roughness = objectRoughness(intersection.objectPtr);
            transparency = objectTransparency(intersection.objectPtr);
            refractiveIndex = objectRefractiveIndex(intersection.objectPtr);
            lambertianContribution = colorMult(sumOfLambertians(normalRay, lights, objects), roughness);
            reflectiveContribution = colorMult(traceRay(
                                                        reflection(ray, normalRay),
                                                        objects,
                                                        lights,
                                                        skybox,
                                                        (int) (numberOfReflections * (1.0 - roughness))
                                                        ), (1.0 - roughness));
            refractiveContribution = colorMult(traceRay(
                                                        refraction(ray, normalRay, intersection.distance, refractiveIndex),
                                                        objects,
                                                        lights,
                                                        skybox,
                                                        (int) (numberOfReflections * (transparency))
                                                        ), (transparency));
            outputColor = colorProd(color, colorSum(lambertianContribution,
                                                    colorSum(reflectiveContribution,
                                                             refractiveContribution)));
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
    Vector pointLightSample;
    int x;
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
                for (x = 0; x < 10; x++)
                {
                    pointLightSample = vecMult(vecNormal(newVector((double) rand(), (double) rand(), (double) rand())), lights->light.pointLight.radius);
                    rayToLight.direction = vecsSub(vecsAdd(lights->light.pointLight.position, pointLightSample), rayToLight.position);
                    lightDistance = vecLen(rayToLight.direction);
                    vecNormalize(&rayToLight.direction);
                    closest = findClosestObject(rayToLight, objects);
                    if (closest.distance <= 0.0 || closest.distance > lightDistance)
                    {
                        incomingColor = colorSum(incomingColor, colorMult(colorFromLight(lights), vecDot(rayToLight.direction, normalRay.direction)/10.0));
                    }
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

Ray refraction(Ray incoming, Ray normal, double intersectionDist, double objectIndex)
{
    Ray refracted;
    Ray perpendicular;
    double airIndex = 1.000293;
    double index1, index2;
    double dot = vecDot(vecNormal(incoming.direction), normal.direction);
    double h1 = intersectionDist;
    double o1, a1, o2, a2;
    Ray negnormal = normal;
    refracted.position = normal.position;
    if (dot == 0) /* ray is perpendicular to the surface, does not cross */
    {
        refracted.direction = incoming.direction;
    }
    else
    {
        if (dot < 0) /* ray goes from air into the current object */
        {
            index1 = airIndex;
            index2 = objectIndex;
            negnormal.direction = vecNeg(negnormal.direction);
            refracted.position = vecsAdd(refracted.position, vecMult(normal.direction, -2*NORMALMARCH));
        }
        else if (dot > 0) /* ray goes from inside the object out to the atmosphere */
        {
            index1 = objectIndex;
            index2 = airIndex;
            normal.direction = vecNeg(normal.direction);
            dot = vecDot(vecNormal(vecNeg(incoming.direction)), normal.direction);
        }
        a1 = dot * h1;
        o1 = sqrt(h1*h1 - a1*a1);
        o2 = index1 * o1 / (index2 * intersectionDist);
        a2 = sqrt(1 - o2 * o2);
        perpendicular.position = incoming.position;
        perpendicular.direction = vecsAdd(normal.position, vecMult(normal.direction, a1));
        vecNormalize(&(perpendicular.direction));
        perpendicular.position = normal.position;
        refracted.direction = vecNormal(vecsAdd(vecsAdd(perpendicular.position, vecMult(perpendicular.direction, o2)), vecsAdd(normal.position, vecMult(normal.direction, a2))));
    }
    return refracted;
}
