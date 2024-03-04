#include "objects.h"

ObjectNode newPlane(Vector point, Vector normal, Color color)
{
    ObjectNode object;
    object.type = 0;
    object.plane.point = point;
    object.plane.normal = normal;
    vecNormalize(&object.plane.normal);
    object.plane.color = color;
    object.next = NULL;
    return object;
}

ObjectNode newSphere(Vector point, double radius, Color color)
{
    ObjectNode object;
    object.type = 1;
    object.sphere.radius = radius;
    object.sphere.point = point;
    object.sphere.color = color;
    object.next = NULL;
    return object;
}
