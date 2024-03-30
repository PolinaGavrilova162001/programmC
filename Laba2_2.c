Объявить массив данных типа int размером 2 на 2.
Ввести с консоли его значения,
вывести на консоль квадрат данной матрицы.

#include <stdio.h>

int main()
{
	int m=2;
    double massiv[m][m];
    
    for (int i=0; i<m; i++)
        for (int j=0; j<m; j++)
        {
            printf("massiv[%d][%d] = ", i+1, j+1);
            scanf("%lf", &massiv[i][j]);
        }
    int kv_m[m][m];
    int i, j, k = 0, l;
        for (i = 0; i < m; i++)
            for (j = 0; j < m; j++)
            {
                kv_m[i][j] = 0;
                for (l = 0; l < m; l++)
                    kv_m[i][j] += (massiv[i][l] * massiv[l][j]);
            }
    for (i = 0; i<m; i++)
    {
        for (j = 0; j<m; j++)
        {
            printf("%d  ", kv_m[i][j]);
        }
        printf("\n");
    }
    return 0;
}
