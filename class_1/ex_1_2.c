#include <stdio.h>

#define NUM_STUDENTS 5
#define NUM_SUBJECTS 2

int main() {
    int grades[NUM_SUBJECTS][NUM_STUDENTS];
    float averages[NUM_SUBJECTS] = {0};

    // Wprowadź oceny dla matematyki
    printf("Wprowadz oceny z matematyki:\n");
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Uczen %d: ", i + 1);
        scanf("%d", &grades[0][i]);
        averages[0] += grades[0][i];
    }

    // Wprowadź oceny z fizyki
    printf("Wprowadz oceny z fizyki:\n");
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Uczen %d: ", i + 1);
        scanf("%d", &grades[1][i]);
        averages[1] += grades[1][i];
    }

    // Oblicz średnie ocen
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        averages[i] /= NUM_STUDENTS;
    }

    // Wyświetl średnie ocen
    printf("Srednie oceny:\n");
    printf("Matematyka: %.2f\n", averages[0]);
    printf("Fizyka: %.2f\n", averages[1]);

    return 0;
}