#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "triangle.h"

int main()
{
    float a, b, c;
    printf("Vvedite a, b, c: ");
    scanf("%f %f %f", &a, &b, &c);
    
    if (isTriangleValid(a, b, c))
    {
        float p = calculatePerimeter(a, b, c);
        float s = calculatePloshade(a, b, c);
        
        printf("Perimeter: %.2f\n", p);
        printf("Ploshade: %.2f\n", s);
    }
    else
    {
        printf("Treygolnika net\n");
    }
    return 0;
}
