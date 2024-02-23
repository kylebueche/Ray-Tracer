#include "intersections.h"
#include "vectormath.h"
#include "shapes.h"

/** returns the distance which the ray intersects the plane, or -1.0 if parallel. **/

double intersectsPlane(Ray ray, Plane plane)
{
    double returnVal = -1.0;
    double x = vecDot(ray.direction, plane.normal);
    if (x != 0.0)
    {
        returnVal = (vecDot(plane.point, plane.normal) - vecDot(ray.point, plane.normal)) / x;
    }
    return returnVal;
}

double intersectsSphere(Ray ray, Sphere sphere)
{
    double intersection1;
    double intersection2;
    double returnVal = -1.0;
    Vector origin = vecsSub(ray.point, sphere.point);
    Vector a = vecsMult(ray.direction, ray.direction);
    Vector b = vecMult(vecsMult(origin, ray.direction), 2);
    Vector c = vecsMult(origin, origin);
    double delta = vecsSub(vecsmult(b, b), vecMult(vecsMult(a, c), 4));
    if (delta == 0)
    {
        do this
    } else if (delta > 0)
        do this
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
