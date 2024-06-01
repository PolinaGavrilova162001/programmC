#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

void printMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d", matrix[i][j]);
        }
        printf("/n");
    }
}

void matrixAdd(int** matrix1, int** matrix2, int** result, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void matrixMultiply(int** matrix1, int rows1, int cols1, int** matrix2, int cols2, int** result) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    clock_t t_start,t_end;
    t_start = clock();
    float duration;
    int i;
    
    for (int i=0; i<10000000; i++);
    
    srand(time(0));
    
    int rows1, cols1, rows2, cols2;
    printf("Введите количество строк в первой матрице: ");
    scanf("%d", &rows1);
    printf("Введите количество столбцов в первой матрице: ");
    scanf("%d", &cols1);
    
    printf("Введите количество строк во второй матрице: ");
    scanf("%d", &rows2);
    printf("Введите количество столбцов во второй матрице: ");
    scanf("%d", &cols2);
    
    int **matrix1 = (int **)malloc(rows1 * sizeof(int *));
    int **matrix2 = (int **)malloc(rows2 * sizeof(int *));
    int **resultSum = (int **)malloc(rows1 * sizeof(int *));
    int **resultMult = (int **)malloc(rows1 * sizeof(int *));
    
    for (int i = 0; i < rows1; i++) {
        matrix1[i] = (int *)malloc(cols1 * sizeof(int));
        resultSum[i] = (int *)malloc(cols1 * sizeof(int));
        resultMult[i] = (int *)malloc(cols2 * sizeof(int));
    }
    
    for (int i = 0; i< rows2; i++) {
        matrix2[i] = (int *)malloc(cols2 * sizeof(int));
    }
    
    generateMatrix(matrix1, rows1, cols1);
    generateMatrix(matrix2, rows2, cols2);
    
    printf("Матрица 1:\n");
    printMatrix(matrix1, rows1, cols1);
    printf("\nМатрица 2:\n");
    printMatrix(matrix2, rows2, cols2);
    
    matrixAdd(matrix1, matrix2, resultSum, rows1, cols1);
    matrixMultiply(matrix1, rows1, cols1, matrix2, cols2, resultMult);
    
    FILE *outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Ошибка в открытии файла\n");
        return 1;
    }
    
    printf("\nСумма матриц:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            fprintf(outputFile, "%d", resultSum[i][j]);
        }
        fprintf(outputFile, "\n");
    }
    
    printf("\nПроизведение матриц:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            fprintf(outputFile, "%d", resultMult[i][j]);
        }
        fprintf(outputFile, "\n");
    }
    
    fclose(outputFile);
    
    for (int i = 0; i < rows1; i++) {
        free(matrix1[i]);
        free(resultSum[i]);
        free(resultMult[i]);
    }
    
    for (int i = 0; i < rows2; i++) {
        free(matrix2[i]);
    }
    free(matrix1);
    free(matrix2);
    free(resultSum);
    free(resultMult);
    
    duration = (clock() - t_start) / (double) CLOCKS_PER_SEC;
    printf("Need_time duration  = %f",duration);
    return 0;
}
