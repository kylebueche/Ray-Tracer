struct vector3d
{
    double x;
    double y;
    double z;
}

vector3d v3dAdd(vector3d&, vector3d&);

vector3d v3dSubtract(vector3d&, vector3d&);

vector3d v3dMultiply(vector3d&, double);

vector3d v3dDivide(vector3d&, double);

double v3dLength(vector3d&);
