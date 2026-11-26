#include <stdio.h>

#define ANZAHL_STUDENTS 3

typedef struct {
    char nachname[30];
    char vorname[30];
    int jahrgang;
    float groesse;
} TPerson;

// Funktionsprototypen
void sortStudentsByHeight(TPerson students[], int anzahl);
void printStudents(const TPerson students[], int anzahl);

int main(void)
{
    TPerson students[] = {
        { "Mueller", "Peter", 1985, 1.72f },
        { "Zbinden", "Marc",  1995, 1.62f },
        { "Meier",   "Hans",  1920, 1.89f }
    };

    printf("Namen sortieren\n");
    printf("----------------\n");

    printf("Unsortiert:\n");
    printStudents(students, ANZAHL_STUDENTS);

    sortStudentsByHeight(students, ANZAHL_STUDENTS);

    printf("Sortiert :\n");
    printStudents(students, ANZAHL_STUDENTS);

    return 0;
}

//Funktionen

void sortStudentsByHeight(TPerson students[], int anzahl)
{
    TPerson temp;

    for (int i = 0; i < anzahl - 1; i++)
    {
        for (int j = 0; j < anzahl - 1 - i; j++)
        {
            if (students[j].groesse > students[j + 1].groesse)
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
        printf("  %s %s Geboren: %d Groesse: %.2f m\n",
               students[i].nachname, students[i].vorname,
               students[i].jahrgang, students[i].groesse);
    }
}
