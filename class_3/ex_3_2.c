#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int rows, cols;

    printf("Podaj liczbe wierszy: ");
    scanf_s("%d", &rows);

    printf("Podaj liczbe kolumn: ");
    scanf_s("%d", &cols);

    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    srand(time(NULL));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = rand() % 100;
        }
    }

    printf("Zawartosc macierzy:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}