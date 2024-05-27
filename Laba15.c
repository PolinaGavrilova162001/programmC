Дано натуральное число N. Выведите все его цифры по одной, в обычном порядке (а потом в обратном), разделяя их пробелами или новыми строками. Например: 179 => 1 7 9; 179 => 9 7 1
При решении этой задачи нельзя использовать строки, списки, массивы (ну и циклы, разумеется).

#include <stdio.h>

void printDigitsForward(int n) {
    if (n == 0) return;
    printDigitsForward(n / 10);
    printf("%d ", n % 10);
}

void printDigitsReverse(int n) {
    if (n == 0) return;
    printDigitsReverse(n / 10);
    printf("%d ", n % 10);
}

int main() {
    int n;
    printf("Введите натуральное число: ");
    scanf("%d", &n);

    printf("Цифры числа %d в обычном порядке:\n", n);
    printDigitsForward(n);

    printf("\nЦифры числа %d в обратном порядке:\n", n);
    printDigitsReverse(n);

    return 0;
}
