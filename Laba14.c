Написать программу подсчитывающая количество битов, выставленных в единицу у числа типа long и double. Сами значения чисел вводятся с клавиатуры.    

#include <stdio.h>
#include <stdint.h>

// Функция подсчитывающая количество битов, выставленных в единицу у числа типа long
uint64_t count_bits_long(long num) {
    uint64_t count = 0;
    while (num) {
        num &= (num - 1);
        count++;
    }
    return count;
}

// Функция подсчитывающая количество битов, выставленных в единицу у числа типа double
uint64_t count_bits_double(double num) {
    uint64_t count = 0;
    // Преобразуем double в long long
    long long int_part = (long long)num;
    // Подсчитываем количество битов для целой части
    count += count_bits_long(int_part);
    // Преобразуем дробную часть в целое число и добавляем количество битов для нее
    uint64_t frac_part = *(uint64_t*)&num;
    count += count_bits_long(frac_part);
    return count;
}

int main() {
    long num_long;
    double num_double;

    printf("Введите число типа long: ");
    scanf("%ld", &num_long);

    printf("Введите число типа double: ");
    scanf("%lf", &num_double);

    uint64_t bits_long = count_bits_long(num_long);
    uint64_t bits_double = count_bits_double(num_double);

    printf("Количество битов, выставленных в единицу для числа типа long: %llu\n", bits_long);
    printf("Количество битов, выставленных в единицу для числа типа double: %llu\n", bits_double);

    return 0;
}
