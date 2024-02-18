3. Решение квадратных уравнений с запросом ввода коэффициентов.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double a, b, c, D=0, x1, x2;
    
    printf("Vvedite a: ");
    scanf("%lf", &a);
    printf("Vvedite b: ");
    scanf("%lf", &b);
    printf("Vvedite c: ");
    scanf("%lf", &c);
    
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

