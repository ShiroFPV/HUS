#include <stdio.h>

#define ANZAHL_STUDENTS 4

typedef struct {
    char vorname[30];
    char nachname[30];
} TPerson;

// Funktionsprototypen
void printStudents(const TPerson students[], int anzahl);

int main(void)
{
    TPerson students[ANZAHL_STUDENTS] = {
        { "Tom", "Bolt" },
        { "Florian", "Finschi" },
        { "Hagmann", "Kai" },
        { "Hardegger", "Kim" }
    };

    printStudents(students, ANZAHL_STUDENTS);

    return 0;
}

//Funktionen

void printStudents(const TPerson students[], int anzahl)
{
    for (int i = 0; i < anzahl; i++)
    {
        printf("%s %s\n", students[i].nachname, students[i].vorname);
    }
}
