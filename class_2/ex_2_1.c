#include <stdio.h>

int main() {
    int number = 10;
    int *ptr = &number; 

    *ptr = 20; 

    printf("Wartosc zmiennej: %d\n", number); 
    printf("Wartosc zmiennej przez wskaznik: %d\n", *ptr);

    return 0;
}