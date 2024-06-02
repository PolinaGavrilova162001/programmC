#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void fill_matrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = random_number(1, 10); // генерируем числа от 1 до 10
        }
    }
}

void print_matrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void free_matrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int **multiply_matrices(int **matrix1, int rows1, int cols1, int **matrix2, int rows2, int cols2) {
    if (cols1 != rows2) {
        printf("Ошибка: нельзя умножать матрицы с такими размерностями\n");
        return NULL;
    }

    int **result = (int **)malloc(rows1 * sizeof(int *));
    for (int i = 0; i < rows1; i++) {
        result[i] = (int *)malloc(cols2 * sizeof(int));
    }

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

int **add_matrices(int **matrix1, int **matrix2, int rows, int cols) {
    int **result = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        result[i] = (int *)malloc(cols * sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    return result;
}

int main() {
    srand(time(NULL));

    int rows, cols;

    printf("Введите количество строк: ");
    scanf("%d", &rows);
    printf("Введите количество столбцов: ");
    scanf("%d", &cols);

    int **matrix1 = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix1[i] = (int *)malloc(cols * sizeof(int));
    }

    int **matrix2 = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix2[i] = (int *)malloc(cols * sizeof(int));
    }

    fill_matrix(matrix1, rows, cols);
    fill_matrix(matrix2, rows, cols);

    FILE *input_file = fopen("input.txt", "w");
    if (input_file == NULL) {
        printf("Ошибка при открытии файла input.txt\n");
        return 1;
    }

    fprintf(input_file, "%d %d\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(input_file, "%d ", matrix1[i][j]);
        }
        fprintf(input_file, "\n");
    }

    fprintf(input_file, "\n");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(input_file, "%d ", matrix2[i][j]);
        }
        fprintf(input_file, "\n");
    }

    fclose(input_file);

    free_matrix(matrix1, rows);
    free_matrix(matrix2, rows);

    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Ошибка при открытии файла input.txt\n");
        return 1;
    }

    fscanf(input_file, "%d %d\n", &rows, &cols);

    matrix1 = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix1[i] = (int *)malloc(cols * sizeof(int));
    }

    matrix2 = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix2[i] = (int *)malloc(cols * sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fscanf(input_file, "%d ", &matrix1[i][j]);
        }
    }

    fscanf(input_file, "\n");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fscanf(input_file, "%d ", &matrix2[i][j]);
        }
    }

    fclose(input_file);

    clock_t start_time = clock();

    int **multiplied_matrix = multiply_matrices(matrix1, rows, cols, matrix2, rows, cols);

    int **added_matrix = add_matrices(matrix1, matrix2, rows, cols);

    clock_t end_time = clock();
    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    FILE *output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Ошибка при открытии файла output.txt\n");
        return 1;
    }

    fprintf(output_file, "Результат умножения матриц:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(output_file, "%d ", multiplied_matrix[i][j]);
        }
        fprintf(output_file, "\n");
    }

    fprintf(output_file, "\nРезультат сложения матриц:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(output_file, "%d ", added_matrix[i][j]);
        }
        fprintf(output_file, "\n");
    }

    fclose(output_file);

    printf("Время работы программы: %f секунд\n", execution_time);

    free_matrix(matrix1, rows);
    free_matrix(matrix2, rows);
    free_matrix(multiplied_matrix, rows);
    free_matrix(added_matrix, rows);

    return 0;
}
