#include <stdio.h>

#define MAX_LAENGE 200

// Funktionsprototypen
int countWords(char satz[]);

int main(void)
{
    char satz[MAX_LAENGE];

    printf("Anzahl Woerter bestimmen\n");
    printf("------------------------\n");

    printf("\nSatz eingeben: ");
    fgets(satz, MAX_LAENGE, stdin);

    printf("\nDer Satz enthaelt %d Woerter.\n", countWords(satz));

    return 0;
}

//Funktionen

int countWords(char satz[])
{
    int anzahl = 0;
    int i = 0;
    int imWort = 0;

    while (satz[i] != '\0' && satz[i] != '\n')
    {
        if (satz[i] != ' ' && !imWort)
        {
            anzahl++;
            imWort = 1;
        }
        else if (satz[i] == ' ')
            imWort = 0;

        i++;
    }

    return anzahl;
}
