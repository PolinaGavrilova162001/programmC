#include <stdarg.h>    //подключаем библиотеку

int calculate_sum(int num_args, ...)    //функция суммы
{
    va_list args;
    va_start(args, num_args);
    
    int sum = 0;
    
    for (int i =0; i < num_args; i++)
    {
        sum +=va_arg(args, int);
    }
    
    va_end(args);
    
    return sum;
}

int calculate_max(int num_args, ...)    //функция максимума
{
    va_list args;
    va_start(args, num_args);
    
    int max = va_arg(args,int);
    
    for (int i = 0; i < num_args; i++)
    {
        int current = va_arg(args, int);
        if (current > max)
        {
            max = current;
        }
    }
    
    va_end(args);
    
    return max;
}

int calculate_min(int num_args, ...)    //функция минимума
{
    va_list args;
    va_start(args, num_args);
    
    int min = va_arg(args, int);
    
    for (int i = 1; i < num_args; i++)
    {
        int current = va_arg(args, int);
        if (current < min)
        {
            min = current;
        }
    }
    
    va_end(args);
    
    return min;
}

float calculate_average(int num_args, ...)    //функция среднего арифметического
{
    va_list args;
    va_start(args, num_args);
    
    int sum = 0;
    
    for (int i = 0; i < num_args; i++)
    {
        sum += va_arg(args, int);
    }
    
    va_end(args);
    
    return (float) sum / num_args;
}
