#include <stdio.h>
#include <stdlib.h>

void printPascalTriangle(int n)
{
    int **arr = (int **)malloc(n * sizeof(int *));
    for (int line = 0; line < n; line++)
    {
        arr[line] = (int *)malloc(n * sizeof(int));
        for (int i = 0; i <= line; i++)
        {
            if (line == i || i == 0)
                arr[line][i] = 1;
            else
                arr[line][i] = arr[line - 1][i - 1] + arr[line - 1][i];
            printf("%d ", arr[line][i]);
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    free(arr);
}

int main()
{
    printPascalTriangle(5);
}