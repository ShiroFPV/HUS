#include <stdio.h>
#include <string.h>

#define ANZAHL_STUDENTS 3

typedef struct {
    char nachname[30];
    char vorname[30];
} TPerson;

// Funktionsprototypen
void sortStudents(TPerson students[], int anzahl);
void printStudents(const TPerson students[], int anzahl);

int main(void)
{
    TPerson students[] = {
        { "Mueller", "Peter" },
        { "Zbinden", "Marc" },
        { "Meier", "Hans" }
    };

    printf("Namen sortieren\n");
    printf("----------------\n");

    printf("Unsortiert:\n");
    printStudents(students, ANZAHL_STUDENTS);

    sortStudents(students, ANZAHL_STUDENTS);

    printf("Sortiert :\n");
    printStudents(students, ANZAHL_STUDENTS);

    return 0;
}

//Funktionen

void sortStudents(TPerson students[], int anzahl)
{
    TPerson temp;

    for (int i = 0; i < anzahl - 1; i++)
    {
        for (int j = 0; j < anzahl - 1 - i; j++)
        {
            if (strcmp(students[j].nachname, students[j + 1].nachname) > 0)
            {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void printStudents(const TPerson students[], int anzahl)
{
    for (int i = 0; i < anzahl; i++)
    {
        printf("  %s %s\n", students[i].nachname, students[i].vorname);
    }
}
