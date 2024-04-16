Написать программу вычисления максимального числа из введенных пользователем в виде одной строки.
Использовать для этого макрос (без функции), на вход которому подается массив чисел и их количество.
____________________________________________________________
#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main()
{
    int numbers[100];
    int count;
    
    printf("Vvedite kolichestvo chisel: ");
    scanf("%d", &count);
    
    printf("Vvedite chisla cherez probel: ");
    for (int i=0; i < count; i++)
    {
        scanf("%d", &numbers[i]);
    }
    
    int max = numbers[0];
    for (int i=1; i < count; i++)
    {
        max = MAX(max, numbers[i]);
    }
    
    printf("Maximalnoe chislo: %d\n", max);
    
    return 0;
}
