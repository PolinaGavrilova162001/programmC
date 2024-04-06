#include <stdio.h>
#include <stdlib.h>

double* operation(double* v1, double* v2, int n, char op) {  //функция для операций над векторами
    double* result = (double*) malloc(n * sizeof(double));
    
    for (int i = 0; i < n; i++) {  //цикл для операций
        if (op == '+') {  //сложение векторов
            result[i] = v1[i] + v2[i];
        } else if (op == '-') {  //вычитание векторов
            result[i] = v1[i] - v2[i];
        } else if (op == '*') {  //умножение векторов
            result[i] = v1[i] * v2[i];
        } else if (op =='/') {  //деление векторов
            result[i] = v1[i] / v2[i];
        } else {  //если операция не введена
            printf("Такой функции нет\n");
            return NULL;
        }
    }
    
    return result;
}

int main() {
    int n;  //размерность векторов
    printf("n: ");
    scanf("%d", &n);

    double* v1 = (double*) malloc(n * sizeof(double));  //первый вектор
    double* v2 = (double*) malloc(n * sizeof(double));  //второй вектор

    printf("Введите элементы первого вектора:\n");  //заполнение элементами первого вектора
    for (int i = 0; i < n; i++) {
        scanf("%lf", &v1[i]);
    }

    printf("Введите элементы второго вектора:\n");  //заполнение элементами второго вектора
    for (int i = 0; i < n; i++) {
        scanf("%lf", &v2[i]);
    }

    char op;  //выбор операции, которая будет проводиться над векторами
    printf("Введите операцию +, -, *, /: ");
    scanf(" %c", &op);

    double* result = operation(v1, v2, n, op);

    if (result != NULL) {  //вывод результата операции над векторами
        printf("Результат операции:\n");
        for (int i = 0; i < n; i++) {
            printf("%lf ", result[i]);
        }
        printf("\n");

        free(result);
    }

    free(v1);  //очистка динамической памяти
    free(v2);

    return 0;
}
