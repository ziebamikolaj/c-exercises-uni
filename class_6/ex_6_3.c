#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int multiply(int a, int b)
{
    return a * b;
}

int subtract(int a, int b)
{
    return a - b;
}

int main()
{
    int a, b, choice, result;
    int (*operation)(int, int);

    printf("Provide two numbers (ints):\n");
    scanf("%d %d", &a, &b);

    printf("Choose operation (1 - add, 2 - multiply, 3 - subtract):\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        operation = add;
        break;
    case 2:
        operation = multiply;
        break;
    case 3:
        operation = subtract;
        break;
    default:
        printf("Wrong choice!\n");
        return 1;
    }

    result = operation(a, b);
    printf("Result: %d\n", result);

    return 0;
}