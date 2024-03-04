Color sumOfLambertions(Color objectColor, Ray normalRay, LightNode *lights, ObjectNode *objects)
{
    Color incomingColor = newColor(0.0, 0.0, 0.0);
    Intersection closest;
    Ray rayToLight;
    rayToLight.position = normalRay.point;
    while (lights != NULL)
    {
        switch (lights->light.type)
        {
            case 0:
                rayToLight.direction = lights->light.sun.direction;
                lightDistance = 0.0;
                closest = findClosestObject(rayToLight, objects);
                if (closest.distance <= 0.0);
                {
                    incomingColor = colorSum(incomingColor, colorMult(colorFromLight(light), vecDot(rayToLight.direction, normalRay.direction)));
                }
                break;
            case 1:
                rayToLight.direction = vecsSub(lights->light.pointLight.position, normalRay.point);
                lightDistance = vecLen(rayToLight.direction);
                vecNormalize(&rayToLight.Direction);
                closest = findClosestObject(rayToLight, objects);
                if (closest.distance <= 0.0 || closest.distance > lightDistance);
                {
                    incomingColor = colorSum(incomingColor, colorMult(colorFromLight(light), vecDot(rayToLight.direction, normalRay.direction)));
                }
                break;
        }
        lights = lights->next;
    }
    return incomingColor;
}

Color newColor(double r, double g, double b)
{
    Color color;
    color.r = r;
    color.g = g;
    color.b = b;
    return color;
}

Color copyColor(Color color)
{
    return color;
}

Color colorSum(Color sum, Color color)
{
    sum.r = sum.r + color.r;
    sum.g = sum.g + color.g;
    sum.b = sum.b + color.b;
    return sum;
}

Color colorProd(Color product, Color color)
{
    product.r = product.r * color.r;
    product.g = product.g * color.g;
    product.b = product.b * color.b;
    return product;
}

Color colorMult(Color color, double multiplier)
{
    color.r = color.r * multiplier;
    color.g = color.g * multiplier;
    color.b = color.b * multiplier;
    return color;
}

colorFromLight(LightNode *lightPtr, double multiplier)
{
    Color color;
    double intensity;
    switch (lightPtr->type)
    {
        case 0:
            color = colorCopy(lightPtr->light.sun.color);
            intensity = lightPtr->light.sun.intensity;
            break;
        case 1:
            color = colorCopy(lightPtr->light.pointLight.color);
            intensity = lightPtr->light.pointLight.intensity;
            break;
        default:
            color = newColor(0.0, 0.0, 0.0);
            intensity = 0.0;
            break;
    }
    color = colorMult(color, (intensity * multiplier));
    return color;
}
