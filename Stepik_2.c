Напишите программу, которая считает сумму двух целых чисел.

#include <stdio.h>  //подключаем основную библиотеку

int main()  //основная функция кода
{
int num1, num2, sum;  //вводим переменные num1, num2, sum
scanf("%d", &num1);  //считываем значение в переменную num1
scanf("%d", &num2);  //считываем значение в переменную num2
sum = num1 + num2;  //в переменную sum заносим значение суммы переменных num1 и num2
printf("%d\n", sum);  //выводим значение переменной sum

return 0;  //конец функции main
}
