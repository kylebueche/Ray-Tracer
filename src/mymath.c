#include "mymath.h"
#include <stdio.h>

double sqr(double x)
{
    return x * x;
}

double sqrt(double x)
{
    double sqrt = x;
    double epsilon = 0.000001;
    if (x < 0.0)
    {
        return -1.0;
    }
    while (sqrt * sqrt > x + epsilon || sqrt * sqrt < x - epsilon)
    {
        sqrt = (sqrt + (x / sqrt)) / 2;
    }
    return sqrt;
}
