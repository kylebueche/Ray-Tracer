struct Point // a value of 1 means 1 meter
{
    float x;
    float y;
    float z;
};

struct Rotation
{
    float x;
    float y;
    float z;
};

struct Color // valid values are from 0 to 255
{
    char r;
    char g;
    char b;
    char a;
};

struct Triangle
{
    Point origin;
    Color color;
    Point v1;
    Point v2;
    Point v3;
};

struct Ray
{
    Point origin;
    Rotation direction;
};

struct Camera // this camera uses points for light in each pixel,
	      // but what if each pixel averaged a square grid of
	      // light akin to a real camera? (points don't exist,
	      // we just have really really small sensors in cams)
	      //
	      // Update: this is called multi sampling and the
	      // issue is that for x samples per pixel, it takes
	      // x times longer for the frame to generate.
	      //
	      // Solution?: We shoot rays at the corners of each
	      // pixel and average each corner to determine the
	      // pixel. This only takes (length * width) +
	      // length + width - 1 rays.
{
    int pixelWidth;
    int pixelHeight;
    float sensorWidth;
    float sensorHeight;
    float sensorDistance;
    Point origin;
};


