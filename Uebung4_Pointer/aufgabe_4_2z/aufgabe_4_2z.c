#include <stdio.h>

#define MAX_LAENGE 100

// Funktionsprototypen
int findSecondWord(char *satz);

int main(void)
{
    char satz[MAX_LAENGE];
    char *pPointer1;
    char *pPointer2;
    char hilf;
    int index;

    printf("Buchstaben tauschen 2\n");
    printf("---------------------\n");

    printf("\nSatz eingeben (max. %d Zeichen): ", MAX_LAENGE - 2);
    if (fgets(satz, MAX_LAENGE, stdin) == NULL)
        return 1;

    for (char *p = satz; *p != '\0'; p++)
        if (*p == '\n')
            *p = '\0';

    pPointer1 = satz;
    while (*pPointer1 == ' ')
        pPointer1++;

    index = findSecondWord(satz);
    if (index < 0)
    {
        printf("Der Satz enthaelt kein zweites Wort.\n");
        return 1;
    }

    pPointer2 = satz + index;

    hilf = *pPointer1;
    *pPointer1 = *pPointer2;
    *pPointer2 = hilf;

    printf("\nIndex zweites Wort: %d\n", index);
    printf("Resultat: %s\n", satz);

    return 0;
}

//Funktionen

int findSecondWord(char *satz)
{
    char *p = satz;

    while (*p == ' ')
        p++;
    while (*p != '\0' && *p != ' ')
        p++;
    while (*p == ' ')
        p++;

    if (*p == '\0')
        return -1;

    return (int)(p - satz);
}
