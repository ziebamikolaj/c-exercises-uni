#include <stdio.h>

int main() {
    int number;
    int sum = 0;

    printf("Podaj liczbe: ");
    scanf("%d", &number);

    if (number < 0) {
        printf("Liczba jest ujemna. Zwracam 0.\n");
        return 0;
    }

    for (int i = 1; i < number; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }

    printf("Suma wszystkich wielokrotnosci 3 lub 5 ponizej %d wynosi: %d\n", number, sum);

    return 0;
}