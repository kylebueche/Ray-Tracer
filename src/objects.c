#include "objects.h"

ObjectNode newPlane(Vector point, Vector normal, Color color, int roughness)
{
    ObjectNode object;
    object.type = PLANE;
    object.plane.point = point;
    object.plane.normal = normal;
    vecNormalize(&object.plane.normal);
    object.plane.color = color;
    object.plane.roughness = clamp(roughness);
    object.next = NULL;
    return object;
}

ObjectNode newSphere(Vector point, double radius, Color color, int roughness)
{
    ObjectNode object;
    object.type = SPHERE;
    object.sphere.radius = radius;
    object.sphere.point = point;
    object.sphere.color = color;
    object.sphere.roughness = clamp(roughness); 
    object.next = NULL;
    return object;
}
