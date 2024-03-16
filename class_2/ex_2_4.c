#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 50
#define MAX_STUDENTS 100

typedef struct
{
    char name[MAX_NAME_LENGTH];
    float finalGrade;
} Student;

void bubbleSort(Student *students, int size)
{
    int i, j;
    Student temp;

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (students[j].finalGrade < students[j + 1].finalGrade)
            {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main()
{
    Student students[MAX_STUDENTS];

    for (int i = 0; i < MAX_STUDENTS; i++)
    {
        sprintf_s(students[i].name, sizeof(students[i].name), "Student %d", i + 1);
        students[i].finalGrade = (float)(rand() % 101) / 10.0;
    }

    int numStudents = sizeof(students) / sizeof(students[0]);

    bubbleSort(students, numStudents);

    printf("Sorted list of students:\n");
    for (int i = 0; i < numStudents; i++)
    {
        printf("Name: %s, Final Grade: %.2f\n", students[i].name, students[i].finalGrade);
    }

    return 0;
}