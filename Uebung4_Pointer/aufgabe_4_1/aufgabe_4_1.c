#include <stdio.h>

#define ANZAHL_ZAHLEN 10
#define STOPP_ZAHL 99

// Funktionsprototypen
void printNumbers(int *pZahlen, int anzahl);

int main(void)
{
    int zahlen[ANZAHL_ZAHLEN] = { 12, 7, 45, 3, 28, 99, 61, 5, 80, 17 };

    printf("Array mit Pointer ausdrucken\n");
    printf("----------------------------\n\n");

    printNumbers(zahlen, ANZAHL_ZAHLEN);

    return 0;
}

//Funktionen

void printNumbers(int *pZahlen, int anzahl)
{
    int *pEnde = pZahlen + anzahl;

    while (pZahlen < pEnde && *pZahlen != STOPP_ZAHL)
    {
        printf("%d\n", *pZahlen);
        pZahlen++;
    }

    if (pZahlen < pEnde)
        printf("%d gefunden - Ausgabe gestoppt.\n", STOPP_ZAHL);
}
