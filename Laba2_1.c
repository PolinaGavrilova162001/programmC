1. Объявить массив данных типа double размером 3 на 3,
ввести с консоли его значения,
вывести на консоль сумму его элементов, расположенных на главной диагонали
и сумму элементов, расположенных на побочной диагонали.

#include <stdio.h>
int main()
{
        int m=3;
    double massiv[m][m];
    double gl_d, pob_d;
    
    for (int i=0; i<m; i++)
            for (int j=0; j<m; j++)
        {
            printf("massiv[%d][%d] = ", i+1, j+1);
            scanf("%lf", &massiv[i][j]);
        }
        printf("Matrix: ");
        for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%f  ", massiv[i][j]);
        }
        printf("\n");
    }
    
    gl_d = 0;
    pob_d = 0;
 
    for (int i = 0; i < m; i++)
    {
        gl_d += massiv[i][i];
        pob_d += massiv[i][(m-1)-i];
    }
 
    printf("Glavnaya = %f\n", gl_d);
    printf("Pobochnaya = %f\n", pob_d);
    return 0;
}

