#ifndef SHAPES_H

#include "vectormath.h"

/* IMPORTANT: b and c are vectors extending from point a; a is their origin. */
typedef struct
{
    Vector point;
    Vector edge1;
    Vector edge2;
}
