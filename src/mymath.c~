#include "mymath.h"
#include <stdio.h>

double sqr(double x)
{
    return x * x;
}

double sqrt(double x)
{
    double L = 0;
    double R = x;
    if (x < 0.0)
    {
        return -1.0;
    }
    else if (L * L == x)
    {
        return L;
    }
    else if (R * R == x)
    {
        return R;
    }
    else
    {
        return sqrtHelper(x, R);
    }
}

double sqrtHelper(double x, double M)
{
    double epsilon = 0.0001; 
    M = (M + (x / M)) / 2;
    if (M * M > x + epsilon)
    {
        return sqrtHelper(x, M);
    }
    else if (M * M < x - epsilon)
    {
        return sqrtHelper(x, M);
    }
    else
    {
        return M;
    }
}
