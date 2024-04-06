Разместить в динамической памяти 2 массива – 2 матрицы размерностью n на n с элементами типа double (значения n и элементы массивов ввести с консоли).
А также ввести с консоли знак операции: '+', '-' или '*' (сделала и деление и вывод "Такой функции нет").
Написать функцию, вычисляющую сумму, разность или произведение данных матриц (их передать по указателю) и возвращающую указатель на массив-результат.
Разместить эту функцию в отдельном модуле (отличном от того, где располагается функция main()). Выдать на консоль значения полученного вектора.

#include <stdio.h>
#include <stdlib.h>

double **create_matrix(int n)   //функция для создания матрицы
{
   double **m = malloc(sizeof(double*) * n);   //выделяет память под матрицу
   for (int i = 0; i < n; ++i)
   {
      m[i] = calloc(1, sizeof(double) * n);   //выделяет 1 байт на переменную для размерности матрицы
   }
   return m;
}

void destroy_matrix(double **m, int n)   //функция для удаления матрицы из динамической памяти
{ 
   for (int i = 0; i < n; ++i)
   { 
      free(m[i]); 
   } 
   free(m); 
}

double** operation_matrix(double **m1, double **m2, char op, int n)   //функция для выбора операции над матрицами
{
   switch (op)  //цикл для выбора
   {
      case '+':   //сложение матриц
         double **result = create_m(n);
         for (int i=0;i<n;++i)
            for (int j=0;j<n;++j)
               result[i][j] = m1[i][j] + m2[i][j];
               return result;
      case '-':   //вычитание матриц
         double **result2 = create_m(n);
         for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
            result2[i][j] = m1[i][j] - m2[i][j];
            return result2;
      case '*':   //умножение матриц
        double **result3 = create_m(n);
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
            result3[i][j] = m1[i][j] * m2[i][j];
            return result3;
      case '/':   //деление матриц
        double **result4 = create_m(n);
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
            result4[i][j] = m1[i][j]/m2[i][j];
            return result4;
            break;
       default:   //если операция не выбрана
        printf("Takou operacii net\n");
        break;
   }
}
int main(void)
{
int n;
printf("n=");   //запрос на ввод пользователя размерности матрицы
scanf("%d", &n);
double **m1 = create_m(n), **m2 = create_m(n);   //создание матриц
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
scanf("%lf", &m1[i][j]);   //заполнение элементами первой матрицы
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
scanf("%lf", &m2[i][j]);   //заполнение элементами второй матрицы
char op;
printf("+, -, *, /: ");   //выбор операции над матрицами
scanf(" %c", &op);   //ввод операции
double** result = operation_m(m1, m2, op, n);   //выполнение функции для проведения операции над матрицами
for(int i = 0; i < n; ++i)
{
for(int j = 0; j < n; ++j)
{
printf("%.2lf", result[i][j]);
}
puts("");
}
destroy_m(m1, n);   //очистка динамической памяти
destroy_m(m2, n);
destroy_m(result, n);
return 0;
}
