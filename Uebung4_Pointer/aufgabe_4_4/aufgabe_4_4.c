#include <stdio.h>
#include <string.h>

struct sPerson {
    char vorname[30];
    char nachname[30];
    char beruf[30];
    int alter;
};

int main(void)
{
    struct sPerson person;

    strcpy(person.vorname, "Max");
    strcpy(person.nachname, "Muster");
    strcpy(person.beruf, "Programmierer");
    person.alter = 37;

    printf("Personendaten\n");
    printf("-------------\n");
    printf("Name: %s %s, Alter: %d Jahre, Beruf: %s\n",
           person.vorname, person.nachname, person.alter, person.beruf);

    return 0;
}
