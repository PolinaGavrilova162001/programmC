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
