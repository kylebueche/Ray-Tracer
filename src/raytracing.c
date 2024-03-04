#include "raytracing.h"

Color traceRay(Ray ray, ObjectNode *objects, LightNode *lights, Color skybox, int numberOfReflections)
{
    Color outputColor = skybox;
    Color objectColor = { 0 };
    double objectRoughness;
    Intersection intersection = findClosestObject(ray, objects);
    Ray normalRay = { 0 };
    Ray reflectedRay = { 0 };
    if (numberOfReflections > 0)
    {
        numberOfReflections--;
        if (intersection.distance > 0.0)
        {
            normalRay.point = vecsAdd(ray.point, vecMult(ray.direction, intersection.distance));
            switch(intersection.objectPtr->type)
            {
                case 0:
                    normalRay.direction = intersection.objectPtr->plane.normal;
                    objectColor = copyColor(intersection.objectPtr->plane.color);
                    objectRoughness = intersection.objectPtr->plane.roughness;
                    break;
                case 1:
                    normalRay.direction = vecsSub(intersectionPoint, intersection.objectPtr->sphere.point);
                    vecNormalize(&normalRay.direction);
                    objectColor = copyColor(intersection.objectPtr->sphere.color);
                    objectRoughness = intersection.objectPtr->sphere.roughness;
                    break;
            }
            outputColor = colorProd(objectColor,
                                    colorSum(colorMult(sumOfLambertions(normalRay, lightSources), roughness),
                                            colorMult(colorFromLight(traceRay(reflection(ray, normalRay),
                                                    objects, lights, skybox, numberOfReflections)), (1.0 - roughness))));
        }
        else
        {
            numberOfReflections = 0;
        }
        return lightPercent(outputColor, traceRay(reflectedRay, objects, skyBox,);
    }
    else
    {
        return newColor(0.0, 0.0, 0.0);
    }
}

/** normal is facing OUT from the surface **/

Ray reflection(Ray incoming, Ray normal)
{
    incoming.direction = vecsSub(normal.point, incoming.point);
    Vector intermediary = vecsMult(normal.direction, vecDot(vecNeg(incoming.direction), normal.direction));
    Vector endpoint = vecsMult(vecAdd(intermediary, incoming.direction));
    Ray reflected;
    reflected.point = normal.point;
    reflected.direction = vecsSub(endpoint, incoming.direction);
    return reflected;
}
