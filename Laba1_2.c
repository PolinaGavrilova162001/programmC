2. Решение квадратного уравнения с условиями, если дискриминант больше нуля, равен нулю, меньше нуля.

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
    
    if (D>0) {
        x1=(-b+sqrt(D))/(2*a);
        x2=(-b-sqrt(D))/(2*a);
    printf("x1=%lf x2=%lf", x1, x2);
     
    }
    if (D==0) {
        x1=(-b/(2*a));
    }
    if (D<0) {
        printf("Корней нет");
    }
    return 0;
}

