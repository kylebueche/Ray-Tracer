#include "antialiasing.h"

Color antialiasPixel(Color pixel, Color leftPixel, Color topPixel)
{
    pixel.r = (pixel.r + leftPixel.r + topPixel.r) / 3;
    pixel.g = (pixel.g + leftPixel.g + topPixel.g) / 3;
    pixel.b = (pixel.b + leftPixel.b + topPixel.b) / 3;
    return pixel;
}
