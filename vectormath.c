#include "vectormath.h"
#include "math.h"


inline void v3dAdd(vector3d& a, vector3d& b)
{
    a = { (a.x + b.x), (a.y + b.y), (a.z + b.z) };
}

inline void v3dSubtract(vector3d& a, vector3d& b);
{
    a = { (a.x - b.x), (a.y - b.y), (a.z - b.z) };
}

inline void v3dMultiply(vector3d& a, double b);
{
    a = { (a.x * b), (a.y * b), (a.z * b) };
}

inline void v3dDivide(vector3d& a, double b);
{
    a = { (a.x / b), (a.y / b), (a.z / b) };
}

inline double v3dLengthSqr(vector3d& a)
{
    return sqr(a.x) + sqr(a.y) + sqr(a.z);

inline double v3dLength(vector3d& a);
{
    return sqrt(v3dLengthSqr(a));
}

inline v3dNormalize

inline float v3dNormalized(vector3d& a);
{
    v3dDivide(a, v3dLength(a));
}

inline void v3dDotProduct(vector3d& u, vector3d& v)
{
   /* v3dLength(a) * v3dLength(b) * cos( ??? */
}

inline void v3dCrossProduct(vector3d& u, vector3d& v)
{
