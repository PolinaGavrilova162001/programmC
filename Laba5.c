Разместить в динамической памяти 2 массива – 2 матрицы размерностью n на n с элементами типа double (значения n и элементы массивов ввести с консоли).
А также ввести с консоли знак операции: '+', '-' или '*'.
Написать функцию, вычисляющую сумму, разность или произведение данных матриц (их передать по указателю) и возвращающую указатель на массив-результат.
Разместить эту функцию в отдельном модуле (отличном от того, где располагается функция main()). Выдать на консоль значения полученного вектора.

#include <stdio.h>
#include <stdlib.h>

double **createMatrix(int n) {
   double **matrix = malloc(sizeof(double*) * n);
   for (int i = 0; i < n; ++i) {
      matrix[i] = calloc(1, sizeof(double) * n); 
   }
   return matrix;
}

void destroyMatrix(double **matrix, int n) { 
   for (int i = 0; i < n; ++i) { 
      free(matrix[i]); 
   } 
   free(matrix); 
}

double** matrixOperation(double **m1, double **m2, char op, int n) {
   switch (op) {
      case '+':
         double **result = createMatrix(n);
         for (int i=0;i<n;++i)
            for (int j=0;j<n;++j)
result[i][j] = m1[i][j] + m2[i][j];
return result;
case '-':
return createMatrix(n);
case '*':
}
}
int main(void) {
int n;
printf("Введите размер матрицы: ");
scanf("%d", &n);
double **m1 = createMatrix(n), **m2 = createMatrix(n);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
scanf("%lf", &m1[i][j]);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
scanf("%lf", &m2[i][j]);
char op;
printf("Выберите операцию (+, -, *): ");
scanf(" %c", &op);
double** result = matrixOperation(m1, m2, op, n);
for(int i = 0; i < n; ++i){
for(int j = 0; j < n; ++j){
printf("%.2lf", result[i][j]);
}
puts("");
}
destroyMatrix(m1, n);
destroyMatrix(m2, n);
destroyMatrix(result, n);
return 0;
}
