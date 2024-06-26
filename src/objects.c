#include "objects.h"

ObjectNode newPlane(Vector position, Vector normal, Color color, double roughness, double transparency, double refractiveIndex, double glossiness)
{
    ObjectNode objectNode;
    objectNode.type = PLANE;
    objectNode.object.plane.position = position;
    objectNode.object.plane.normal = normal;
    vecNormalize(&objectNode.object.plane.normal);
    objectNode.object.plane.color = color;
    objectNode.object.plane.roughness = clamp(roughness);
    objectNode.object.plane.transparency = clamp(transparency);
    objectNode.object.plane.refractiveIndex = refractiveIndex;
    objectNode.object.plane.glossiness = clamp(glossiness);
    objectNode.next = NULL;
    return objectNode;
}

ObjectNode newSphere(Vector position, double radius, Color color, double roughness, double transparency, double refractiveIndex, double glossiness)
{
    ObjectNode objectNode;
    objectNode.type = SPHERE;
    objectNode.object.sphere.radius = radius;
    objectNode.object.sphere.position = position;
    objectNode.object.sphere.color = color;
    objectNode.object.sphere.roughness = clamp(roughness);
    objectNode.object.sphere.transparency = clamp(transparency);
    objectNode.object.sphere.refractiveIndex = refractiveIndex;
    objectNode.object.sphere.glossiness = clamp(glossiness);
    objectNode.next = NULL;
    return objectNode;
}

Color objectColor(ObjectNode *objectPtr)
{
    switch(objectPtr->type)
    {
        case PLANE:
            return objectPtr->object.plane.color;
        case SPHERE:
            return objectPtr->object.sphere.color;
        default:
            return newColor(0.0, 0.0, 0.0);
    }
}

Vector objectPosition(ObjectNode *objectPtr)
{
    switch(objectPtr->type)
    {
        case PLANE:
            return objectPtr->object.plane.position;
        case SPHERE:
            return objectPtr->object.sphere.position;
        default:
            return newVector(0.0, 0.0, 0.0);
    }
}

Vector objectNormal(ObjectNode *objectPtr, Vector point)
{
    switch(objectPtr->type)
    {
        case PLANE:
            return objectPtr->object.plane.normal;
        case SPHERE:
            return vecNormal(vecsSub(point, objectPtr->object.sphere.position));
        default:
            return newVector(0.0, 0.0, 1.0);
    }
}

double objectRoughness(ObjectNode *objectPtr)
{
    switch(objectPtr->type)
    {
        case PLANE:
            return objectPtr->object.plane.roughness;
        case SPHERE:
            return objectPtr->object.sphere.roughness;
        default:
            return 1.0;
    }
}

double objectTransparency(ObjectNode *objectPtr)
{
    switch(objectPtr->type)
    {
        case PLANE:
            return objectPtr->object.plane.transparency;
        case SPHERE:
            return objectPtr->object.sphere.transparency;
        default:
            return 0.0;
    }
}

double objectRefractiveIndex(ObjectNode *objectPtr)
{
    switch(objectPtr->type)
    {
        case PLANE:
            return objectPtr->object.plane.refractiveIndex;
        case SPHERE:
            return objectPtr->object.sphere.refractiveIndex;
        default:
            return 1.0;
    }
}
