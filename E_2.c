#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    FILE *input_file, *output_file;
    int N, M;
    int i, j;
    int sum_rows = 0, sum_cols = 0;
    clock_t start, end;
    double cpu_time_used;
    printf("Enter the size of the array: ");
    scanf("%d", &N);

    input_file = fopen("input.txt", "w");
    srand(time(NULL));
    for (i = 0; i < N; i++) {
        fprintf(input_file, "%d ", rand() % 100);
    }
    fclose(input_file);

    input_file = fopen("input.txt", "r");
    output_file = fopen("output.txt", "w");
    while (fscanf(input_file, "%d", &j) != EOF) {
        if (j % 35 == 0) {
            fprintf(output_file, "ПЯТЬСЕМЬ ");
        } else if (j % 5 == 0) {
            fprintf(output_file, "ПЯТЬ ");
        } else if (j % 7 == 0) {
            fprintf(output_file, "СЕМЬ ");
        } else {
            fprintf(output_file, "%d ", j);
        }
    }
    fclose(input_file);
    fclose(output_file);

    M = N / 2;
    int matrix[M][2];
    input_file = fopen("input.txt", "r");
    for (i = 0; i < M; i++) {
        for (j = 0; j < 2; j++) {
            fscanf(input_file, "%d", &matrix[i][j]);
        }
    }
    fclose(input_file);

    for (i = 0; i < M; i++) {
        int row_sum = 0;
        for (j = 0; j < 2; j++) {
            row_sum += matrix[i][j];
            sum_cols += matrix[i][j];
        }
        sum_rows += row_sum;
    }

    printf("Matrix:\n");
    for (i = 0; i < M; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("Sum of rows: %d\n", sum_rows);
    printf("Sum of columns: %d\n", sum_cols);

    start = clock();

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by the program: %f seconds\n", cpu_time_used);
    return 0;
}
