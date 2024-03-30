#include <stdio.h>
#include <stdlib.h>

double* operation(double* v1, double* v2, int n, char op) {
    double* result = (double*) malloc(n * sizeof(double));
    
    for (int i = 0; i < n; i++) {
        if (op == '+') {
            result[i] = v1[i] + v2[i];
        } else if (op == '-') {
            result[i] = v1[i] - v2[i];
        } else if (op == '*') {
            result[i] = v1[i] * v2[i];
        } else if (op =='/') {
            result[i] = v1[i] / v2[i];
        } else {
            printf("Такой функции нет\n");
            return NULL;
        }
    }
    
    return result;
}

int main() {
    int n;
    printf("Введите размерность векторов: ");
    scanf("%d", &n);

    double* v1 = (double*) malloc(n * sizeof(double));
    double* v2 = (double*) malloc(n * sizeof(double));

    printf("Введите элементы первого вектора:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &v1[i]);
    }

    printf("Введите элементы второго вектора:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &v2[i]);
    }

    char op;
    printf("Введите операцию +, -, *, /: ");
    scanf(" %c", &op);

    double* result = operation(v1, v2, n, op);

    if (result != NULL) {
        printf("Результат операции:\n");
        for (int i = 0; i < n; i++) {
            printf("%lf ", result[i]);
        }
        printf("\n");

        free(result);
    }

    free(v1);
    free(v2);

    return 0;
}
