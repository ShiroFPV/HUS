#include <stdio.h>

#define MAX_ZAHLEN 200
#define ENDE_ZAHL 9999

// Zum Testen von Teil 1 auf 1 setzen: das Array wird dann
// fest gefuellt und die Abfrage entfaellt.
#define TESTDATEN 0

// Funktionsprototypen
int readIntegerArray(int zahlen[], int maxAnzahl);
int fillTestArray(int zahlen[]);
void bubbleSort(int zahlen[], int anzahl);
void printIntegerArray(int zahlen[], int anzahl);

int main(void)
{
    int zahlen[MAX_ZAHLEN];
    int anzahl;

    printf("200 Zahlen sortieren\n");
    printf("--------------------\n");

#if TESTDATEN
    anzahl = fillTestArray(zahlen);
#else
    anzahl = readIntegerArray(zahlen, MAX_ZAHLEN);
#endif

    bubbleSort(zahlen, anzahl);

    printf("\n%d sortierte Zahlen:\n", anzahl);
    printIntegerArray(zahlen, anzahl);

    return 0;
}

//Funktionen
int readIntegerArray(int zahlen[], int maxAnzahl)
{
    int anzahl = 0;
    int eingabe;

    printf("\nZahlen eingeben, Ende mit %d\n", ENDE_ZAHL);

    do
    {
        printf("%d. Zahl: ", anzahl + 1);
        scanf("%d", &eingabe);
        while ((getchar()) != '\n');

        if (eingabe != ENDE_ZAHL)
            zahlen[anzahl++] = eingabe;
    }
    while (eingabe != ENDE_ZAHL && anzahl < maxAnzahl);

    return anzahl;
}

int fillTestArray(int zahlen[])
{
    int testwerte[] = { 89, 34, 72, 5, 147, 23, 91, 6, 58, 12 };
    int anzahl = sizeof(testwerte) / sizeof(testwerte[0]);

    for (int i = 0; i < anzahl; i++)
        zahlen[i] = testwerte[i];

    return anzahl;
}

void bubbleSort(int zahlen[], int anzahl)
{
    int hilf;

    for (int durchgang = 0; durchgang < anzahl - 1; durchgang++)
    {
        for (int i = 0; i < anzahl - 1 - durchgang; i++)
        {
            if (zahlen[i] > zahlen[i + 1])
            {
                hilf = zahlen[i];
                zahlen[i] = zahlen[i + 1];
                zahlen[i + 1] = hilf;
            }
        }
    }
}

void printIntegerArray(int zahlen[], int anzahl)
{
    for (int i = 0; i < anzahl; i++)
    {
        printf("%6d", zahlen[i]);
        if ((i + 1) % 10 == 0)
            printf("\n");
    }

    if (anzahl % 10 != 0)
        printf("\n");
}
