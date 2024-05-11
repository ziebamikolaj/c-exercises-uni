#include <stdio.h>

int main()
{
    int numbers[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int *p = &numbers[0]; *p < 10; p++)
    {
        printf("%d", *p);
    }
}