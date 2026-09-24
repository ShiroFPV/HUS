#include <stdio.h>

#define MAX_LAENGE 200
#define GESUCHTES_ZEICHEN 'a'

// Funktionsprototypen
int countChar(char satz[], char gesucht);

int main(void)
{
    char satz[MAX_LAENGE];

    printf("Anzahl Zeichen zaehlen\n");
    printf("----------------------\n");

    printf("\nSatz eingeben: ");
    fgets(satz, MAX_LAENGE, stdin);

    printf("\nDer Buchstabe '%c' kommt %d mal vor.\n",
           GESUCHTES_ZEICHEN, countChar(satz, GESUCHTES_ZEICHEN));

    return 0;
}

//Funktionen
int countChar(char satz[], char gesucht)
{
    int anzahl = 0;
    int i = 0;

    while (satz[i] != '\0')
    {
        if (satz[i] == gesucht)
            anzahl++;
        i++;
    }

    return anzahl;
}
