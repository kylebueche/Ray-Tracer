inline double sqr(double x)
{
    return x * x;
}

inline double sqrt(double x)
{
    double epsilon = 0.000001;
    double guess = x / 2.0;
    while ((guess * guess - x) > epsilon || (x - guess * guess) > epsilon)
    {
        guess = (guess + (x / guess)) / 2.0;
    }
    return guess;
}
