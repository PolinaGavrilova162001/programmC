Написать программу подсчитывающая количество битов, выставленных в единицу у числа типа long и double. Сами значения чисел вводятся с клавиатуры.    

//подключаем библиотеку
#include <stdio.h>
#include <stdint.h>

// Функция подсчитывающая количество битов, выставленных в единицу у числа типа long
uint64_t count_bits_long(long num) {
    uint64_t count = 0;    //вводим переменную
    while (num) {    
        num &= (num - 1);    //сбрасывает крайний правый установленный бит в числе num
        count++;    //увеличиваем переменную (установленные биты)
    }
    return count;    //возвращаем значение переменной
}

// Функция подсчитывающая количество битов, выставленных в единицу у числа типа double
uint64_t count_bits_double(double num) {
    uint64_t count = 0;
    // Преобразуем double в long long
    long long int_part = (long long)num;
    // Подсчитываем количество битов для целой части
    count += count_bits_long(int_part);
    // Преобразуем дробную часть в целое число и добавляем количество битов для нее
    uint64_t frac_part = *(uint64_t*)&num;    //преобразуем num в uint64_t
    count += count_bits_long(frac_part);    //считаем количество установленных битов в числе frac_part
    return count;    //возвращаем переменную
}

int main() {
    long num_long;    //вводим переменную
    double num_double;    //вводим переменную

    printf("Введите число типа long: ");    //выводим текст-запрос
    scanf("%ld", &num_long);    //заносим значение в переменную

    printf("Введите число типа double: ");    //выводим текст-запрос
    scanf("%lf", &num_double);    //заносим значение в переменную

    uint64_t bits_long = count_bits_long(num_long);    //подсчитываем число установленных бит в переменной num_long
    uint64_t bits_double = count_bits_double(num_double);    //подсчитываем число установленных бит в переменной num_double

    printf("Количество битов, выставленных в единицу для числа типа long: %llu\n", bits_long);    //выводим переменную
    printf("Количество битов, выставленных в единицу для числа типа double: %llu\n", bits_double);    //выводим переменную

    return 0;    //конец
}
