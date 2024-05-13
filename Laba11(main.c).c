Создать в отдельном модуле функции с переменным количеством аргументов, которая вычисляет их сумму, максимум, минимум, среднее арифметическое.
____________________
#include <stdio.h>
#include "functions.h"

int main()
{
    int sum = calculate_sum(3, 5, 10, 15);
    int max = calculate_max(4, 20, 30, 15, 25);
    int min = calculate_min(5, 10, 100, 30, 50, 20);
    float average = calculate_average(4, 5, 10, 15, 20);
    
    printf("Sum: %d\n", sum);
    printf("Max: %d\n", max);
    printf("Min: %d\n", min);
    printf("Average: %.2f\n", average);
    
    return 0;
}
