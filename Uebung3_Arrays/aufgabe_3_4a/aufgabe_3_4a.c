#include <stdio.h>

#define MAX_LAENGE 200

// Funktionsprototypen
int myStrlen(char satz[]);

int main(void)
{
    char satz[MAX_LAENGE];

    printf("Satzlaenge bestimmen\n");
    printf("--------------------\n");

    printf("\nSatz eingeben: ");
    fgets(satz, MAX_LAENGE, stdin);

    printf("\nDer Satz hat %d Zeichen.\n", myStrlen(satz));

    return 0;
}

//Funktionen

int myStrlen(char satz[])
{
    int laenge = 0;

    while (satz[laenge] != '\0' && satz[laenge] != '\n')
        laenge++;

    return laenge;
}
