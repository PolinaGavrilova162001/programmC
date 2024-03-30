1) Написать функции, вычисляющие периметр и площадь треугольника по значениям длин трёх его сторон.
2) Разместить их в отдельном модуле (отличном от того, где располагается функция main( )).
3) Ввести с консоли значения длин сторон треугольника (с проверкой на корректность неравенства треугольника)
и выдать на консоль вычисленные с помощью написанных функций значения его периметра и площади.

#include <stdio.h>
#include <math.h>

double a, b, c;

void perimetr(double x, double y, double z)
{ 
    printf("Perimetr %g\n", x + y + z); 
    
}

void ploshchadj(double x, double y, double z)
{
    printf("Ploshad %g\n", ((x + y + z)/2));
}

int main() {
    double a, b, c; printf("a b c: ");
scanf("%lf%lf%lf", &a, &b, &c); 
if (a <= 0 || b <= 0
|| c <= 0 || a + b <= c || b + c <= a || c + a <= b)  //|| - логическое или
printf("Treygolnika net");
else {
    perimetr(a, b, c); ploshchadj(a, b, c); 
    
} 
    
}
