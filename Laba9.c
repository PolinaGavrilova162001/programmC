Реализовать программу-калькулятор с возможностью выполнения арифметических действий (+, -), унарный и бинарный вариант. У пользователя запрашивается выражение, например, "-123.5 + 4 - 456+56", программа должна решить выражение. Для разбора входной строки использовать функцию strok.


#include <stdio.h>    //подключение библиотек
#include <string.h>
#include <stdlib.h>

double unary_op(char op, double operand)    //функция унарный вариант
{
    if (op == '-')    //если операция имеет -
    {
        return -operand;    //функция возвращает оперант отрицательный
    }
    else    //иначе
    {
        return operand;    //возвращает оперант положительный
    }
}

double calculate(char *expression)    //функция калькулятор
{
    double result = 0.0;    //вводим переменную result
    char *token;    //строку token и делаем указатель на первый ее элемент
    char *delimiter = " ";    //строку delimiter и делаем указатель на первый элемент, пустая строка
    
    token = strtok(expression, delimiter);    //в строке token делим ее на лексемы по указанному указателю
    
    if (token != NULL)    //если строка token не пустая
    {
        result = atof(token);    //переводим переменную result к числовому виду строки token
    }
    
    while ((token = strtok(NULL, delimiter)) != NULL)    //если строка token поделена и не пустая
    {
        char op = token[0];    //в строку op вводим строку token
        token = strtok(NULL, delimiter);    //строку token делим
        double operand = atof(token);    //переменную operand приводим в числовой вид строки token
        
        if (op == '+' || op == '-')    //если переменная op имеет значение + или -
        {
            result += unary_op(op, operand);    //тогда переменная result получает значение функции 
        }
        else    //иначе
        {
            printf("Error");    //выводит текст
            return 0.0;    //возвращает нули
        }
    }
    return result;    //возвращает значение переменной result
}

int main()    //основная функция
{
    char expression[100];    //вводим строку
    
    printf("Vvedite arifmeticheskoe vurajenie: ");    //выводим текст-запрос
    fgets(expression, sizeof(expression), stdin);    //считывает символы из потока и сохраняет их в виде строки в параметр expression до тех пор пока не наступит конец строки или пока не будет достигнут конец файла
    
    if (expression[strlen(expression) - 1] == '\n')
    {
        expression[strlen(expression) - 1] = '\0';
    }
    
    double result = calculate(expression);
    
    printf("Rezultat: %.2f/n", result);
    
    return 0;
}
