#include <stdio.h>

#define ANZAHL 3

// Funktionsprototypen
void sortIntegerArray(int zahlen[]);
void printIntegerArray(int zahlen[]);

int main(void)
{
    int zahlen[ANZAHL];

    printf("3 Zahlen sortieren\n");
    printf("------------------\n");

    for (int i = 0; i < ANZAHL; i++)
    {
        printf("\n%d. Zahl eingeben: ", i + 1);
        scanf("%d", &zahlen[i]);
        while ((getchar()) != '\n');
    }

    sortIntegerArray(zahlen);

    printf("\nSortierte Werte:\n");
    printIntegerArray(zahlen);

    return 0;
}

//Funktionen

// 3 Verzweigungen sind noetig: nach diesen 3 Vergleichen
// (a<->b, b<->c, a<->b) ist jede Reihenfolge sortiert.
void sortIntegerArray(int zahlen[])
{
    int hilf;

    if (zahlen[0] > zahlen[1])
    {
        hilf = zahlen[0];
        zahlen[0] = zahlen[1];
        zahlen[1] = hilf;
    }

    if (zahlen[1] > zahlen[2])
    {
        hilf = zahlen[1];
        zahlen[1] = zahlen[2];
        zahlen[2] = hilf;
    }

    if (zahlen[0] > zahlen[1])
    {
        hilf = zahlen[0];
        zahlen[0] = zahlen[1];
        zahlen[1] = hilf;
    }
}

void printIntegerArray(int zahlen[])
{
    for (int i = 0; i < ANZAHL; i++)
        printf("%d\t", zahlen[i]);
    printf("\n");
}
