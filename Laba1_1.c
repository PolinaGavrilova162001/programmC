1. Решение квадратного уравнения.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double a, b, c, D=0, x1, x2;
    
    a = 1;
    b = 3;
    c = 1;
    
    D = b*b - 4*a*c;
    printf("D = %lf", D);
    
    x1=(-b+sqrt(D))/(2*a);
    x2=(-b-sqrt(D))/(2*a);
    printf("x1=%lf x2=%lf", x1, x2);
    

    return 0;
}

