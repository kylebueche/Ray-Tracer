#include "intersections.h"
#include "vectormath.h"

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
