#include <math.h>
#include <stdbool.h>

bool isTriangleValid(float a, float b, float c)
{
    if (a+b>c&&b+c>a&&a+c>b)
        return true;
    else
    return false;
}

float calculatePerimeter(float a, float b, float c)
{
    return a+b+c;
}

float calculatePloshade(float a, float b, float c)
{
    float p = (a+b+c)/2.0;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
