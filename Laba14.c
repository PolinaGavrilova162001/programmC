Написать программу с использованием нелокального перехода setjmp/longjmp, которая вычисляет сумму чисел Фибоначчи (начиная с1, 1,...). Использовать рекурсивную функции для вычисления суммы, в качестве механизма возврата из вложенных вызовов использовать нелокальный переход.

#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;

long long sum_fibonacci(long long n, long long a, long long b) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return a;
    }
    long long result = a + b;
    if (n - 2 >= 0) {
        longjmp(buf, 0);
        return sum_fibonacci(n - 1, b, result) + result;
    }
    return result;
}

int main() {
    long long n;
    printf("Enter a positive integer: ");
    scanf("%lld", &n);

    if (setjmp(buf) == 0) {
        printf("The sum of the first %lld Fibonacci numbers is: %lld\n", n, sum_fibonacci(n, 1, 1));
    } else {
        printf("Please enter a positive integer: ");
        scanf("%lld", &n);
        printf("The sum of the first %lld Fibonacci numbers is: %lld\n", n, sum_fibonacci(n, 1, 1));
    }

    return 0;
}
