#include "intersections.h"
#include "vectormath.h"
#include "objects.h"
#include "lights.h"
#include <math.h>


/** returns closest object and its distance, or negative dist if no valid intersections occur **/
Intersection findClosestObject(Ray ray, ObjectNode *objects)
{
    double epsilon = 0.00000;
    double contender;
    ObjectNode *currentObj = objects;
    Intersection intersection;
    intersection.objectPtr = NULL;
    intersection.distance = -1.0;
    if (objects != NULL)
    {
        intersection.distance = intersectsObject(ray, currentObj);
        intersection.objectPtr = currentObj;
        while (currentObj != NULL)
        {
            contender = intersectsObject(ray, currentObj);
            if (intersection.distance < epsilon || (contender > epsilon && contender < intersection.distance))
            {
                intersection.distance = contender;
                intersection.objectPtr = currentObj;
            }
            currentObj = currentObj->next;
        }
    }
    return intersection;
}

double intersectsObject(Ray ray, ObjectNode *objectPtr)
{
    switch (objectPtr->type)
    {
        case PLANE:
            return intersectsPlane(ray, objectPtr->object.plane);
        case SPHERE:
            return intersectsSphere(ray, objectPtr->object.sphere);
        default:
            return -1.0;
    }
}

/** returns the distance which the ray intersects the plane, or a negative number if it doesn't. **/

double intersectsPlane(Ray ray, Plane plane)
{
    double returnVal = -1.0;
    double x = vecDot(ray.direction, plane.normal);
    if (x != 0.0)
    {
        returnVal = (vecDot(plane.position, plane.normal) - vecDot(ray.position, plane.normal)) / x;
    }
    return returnVal;
}

/** returns the distance which the ray first intersects the plane, or a negative number if it doesn't. **/

double intersectsSphere(Ray ray, Sphere sphere)
{
    double returnVal = -1.0;
    Vector origin = vecsSub(ray.position, sphere.position);
    double a = vecDot(ray.direction, ray.direction);
    double b;
    double c;
    double insideSqrt;
    double root;
    double i1;
    double i2;
    if (a != 0.0)
    {
        b = 2.0 * vecDot(origin, ray.direction);
        c = vecDot(origin, origin) - (sphere.radius * sphere.radius);
        insideSqrt = (b * b) - (4.0 * a * c);
        if (insideSqrt >= 0.0)
        {
            root = sqrt(insideSqrt);
            i1 = ((0.0 - b) - root) / (2.0 * a);
            i2 = ((0.0 - b) + root) / (2.0 * a);
            returnVal = fmin(fmax(i1, 0.0), fmax(i2, 0.0));
            if (returnVal == 0.0)
            {
                returnVal = -1.0;
            }
        }
    }
    return returnVal;
}

    
/*int intersectsTriangle(Ray ray, Triangle triangle)
{
    int returnVal = 0;
    Point d = intersectsPlane(ray, plane);
    plane plane = { 0 };
    plane.point = vecAddVec(plane.point, triangle.point
    plane.normal = veccross(triangle.edge1, triangle.edge2);
    
    vecNormalize(&plane.normal);

    if (d < 0.0)
    {
        if (vecLen(vecCross(triangle.edge1, triangle.edge2)) == vecLen(vecCross(edge1, ad)) + vecLen(vecCross(edge2, ad)) + vecLen(vecCross(bd, bc)))
        {
            returnVal = 1;
        }
    }
    return returnVal;
}*/
