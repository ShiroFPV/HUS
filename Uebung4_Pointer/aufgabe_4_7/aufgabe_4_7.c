#include <stdio.h>

typedef struct {
    char vorname[30];
    char nachname[30];
    char beruf[30];
    int alter;
} TPerson;

// Funktionsprototypen
void printPerson(const TPerson *pPerson);

int main(void)
{
    TPerson person1 = { "Max", "Muster", "Programmierer", 37 };
    TPerson person2 = { "Rolf", "Morger", "Zahntechniker", 26 };

    printPerson(&person1);
    printPerson(&person2);

    return 0;
}

//Funktionen

void printPerson(const TPerson *pPerson)
{
    printf("Name: %s %s, Alter: %d Jahre, Beruf: %s\n",
           pPerson->vorname, pPerson->nachname, pPerson->alter, pPerson->beruf);
}
