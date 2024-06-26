Написать программу вычисления максимального числа из введенных пользователем в виде одной строки. 
Использовать для этого макрос (без функции), на вход которому подается массив чисел и их количество.

#include <stdio.h>    //подключаем основную библиотеку

#define MAX(x, y)((x) > (y) ? (x):(y))    //макрос для нахождения максимального числа

int main()    //основная функция
{
    int n;    //вводим переменную для обозначения количества элементов
    printf("Vvedite kolichestvo elementov: ");    //выводим текст запроса чтобы пользователь ввел число количества элементов
    scanf("%d", &n);    //заносим значение, введенное пользователем в переменную n
    
    int arri;    //вводим переменную arri для записи элементов
    
    printf("Vvedite %d elementov cherez probel: ", n);    //выводим текст запроса чтобы пользователь ввел через пробел элементы
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arri);    //пока количество элементов меньше выделенной длины для элементов, по циклу элементы будут заноситься в переменную arri
    }
    
    int max = arri;    //вводим переменную max для и приравниваем ее к переменной arri 
    for (int i = 1; i < n; i++)    //цикл перебирает элементы и находит максимальное число
    {
        max = MAX(max, arri);    //максимальное число равно макросу для нахождения максимального числа
    }
    
    printf("Maximalnoe chislo ravno: %d\n", max);    //вывод максимального числа из всех элементов
    
    return 0;    //конец функции main
}
