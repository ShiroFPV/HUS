#include <stdio.h>

#define MAX_LAENGE 100

int main(void)
{
    char satz[MAX_LAENGE];
    char *cPointer1;
    char *cPointer2;
    char hilf;

    printf("Buchstaben tauschen 1\n");
    printf("---------------------\n");

    printf("\nSatz eingeben (max. %d Zeichen): ", MAX_LAENGE - 2);
    if (fgets(satz, MAX_LAENGE, stdin) == NULL)
        return 1;

    for (char *p = satz; *p != '\0'; p++)
        if (*p == '\n')
            *p = '\0';

    cPointer1 = satz;
    while (*cPointer1 == ' ')
        cPointer1++;

    cPointer2 = cPointer1 + 1;

    if (*cPointer1 == '\0' || *cPointer2 == '\0' || *cPointer2 == ' ')
    {
        printf("Das erste Wort hat weniger als 2 Buchstaben.\n");
        return 1;
    }

    hilf = *cPointer1;
    *cPointer1 = *cPointer2;
    *cPointer2 = hilf;

    printf("\nResultat: %s\n", satz);

    return 0;
}
