#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ZAHLEN 200
#define ENDE_ZAHL 9999

// Datenquelle waehlen:
//   0 = Zahlen von Hand eingeben (Ende mit 9999)
//   1 = festes Test-Array
//   2 = 200 Zufallszahlen (am aussagekraeftigsten fuer den Zeitvergleich)
#define DATENQUELLE 2

// Ein einzelner Sortiervorgang von 200 Zahlen dauert nur wenige
// Mikrosekunden - das ist so kurz wie die Messungenauigkeit von clock()
// selbst. Darum wird jedes Verfahren viele Male wiederholt und die
// Gesamtzeit durch die Anzahl Wiederholungen geteilt.
#define WIEDERHOLUNGEN 10000

// Funktionsprototypen
int readIntegerArray(int zahlen[], int maxAnzahl);
int fillTestArray(int zahlen[]);
int fillRandomArray(int zahlen[], int anzahl);
void copyIntegerArray(int quelle[], int ziel[], int anzahl);
void bubbleSort(int zahlen[], int anzahl);
int compareInts(const void *a, const void *b);
int arraysAreEqual(int ersteZahlen[], int zweiteZahlen[], int anzahl);
double sekunden(clock_t start, clock_t ende);
void printIntegerArray(int zahlen[], int anzahl);

int main(void)
{
    int zahlen[MAX_ZAHLEN];
    int arbeit[MAX_ZAHLEN];
    int ergebnisBubble[MAX_ZAHLEN];
    int ergebnisQsort[MAX_ZAHLEN];
    int anzahl;
    clock_t start, ende;

    printf("200 Zahlen sortieren - BubbleSort gegen qsort\n");
    printf("---------------------------------------------\n");

#if DATENQUELLE == 0
    anzahl = readIntegerArray(zahlen, MAX_ZAHLEN);
#elif DATENQUELLE == 1
    anzahl = fillTestArray(zahlen);
#else
    anzahl = fillRandomArray(zahlen, MAX_ZAHLEN);
#endif

    if (anzahl == 0)
    {
        printf("\nKeine Zahlen zum Sortieren vorhanden.\n");
        return 0;
    }

    printf("\n%d Zahlen, je %d Wiederholungen pro Verfahren\n", anzahl, WIEDERHOLUNGEN);

    // Leerlauf: nur kopieren, ohne zu sortieren. Diese Zeit steckt in
    // beiden Messungen unten drin und wird darum abgezogen.
    start = clock();
    for (int w = 0; w < WIEDERHOLUNGEN; w++)
        copyIntegerArray(zahlen, arbeit, anzahl);
    ende = clock();
    double zeitKopieren = sekunden(start, ende);

    // 1. BubbleSort
    start = clock();
    for (int w = 0; w < WIEDERHOLUNGEN; w++)
    {
        copyIntegerArray(zahlen, arbeit, anzahl);
        bubbleSort(arbeit, anzahl);
    }
    ende = clock();
    double zeitBubble = sekunden(start, ende) - zeitKopieren;
    copyIntegerArray(arbeit, ergebnisBubble, anzahl);

    // 2. qsort aus der Standardbibliothek
    start = clock();
    for (int w = 0; w < WIEDERHOLUNGEN; w++)
    {
        copyIntegerArray(zahlen, arbeit, anzahl);
        qsort(arbeit, anzahl, sizeof(int), compareInts);
    }
    ende = clock();
    double zeitQsort = sekunden(start, ende) - zeitKopieren;
    copyIntegerArray(arbeit, ergebnisQsort, anzahl);

    printf("\nVerfahren     Gesamtzeit     pro Durchgang\n");
    printf("-----------------------------------------\n");
    printf("BubbleSort    %8.4f s    %8.2f us\n",
           zeitBubble, zeitBubble / WIEDERHOLUNGEN * 1000000.0);
    printf("qsort         %8.4f s    %8.2f us\n",
           zeitQsort, zeitQsort / WIEDERHOLUNGEN * 1000000.0);

    if (zeitQsort > 0.0 && zeitBubble > 0.0)
        printf("\nqsort ist %.1f mal schneller als BubbleSort.\n", zeitBubble / zeitQsort);

    if (arraysAreEqual(ergebnisBubble, ergebnisQsort, anzahl))
        printf("Beide Verfahren liefern dasselbe Ergebnis.\n");
    else
        printf("ACHTUNG: die Ergebnisse unterscheiden sich!\n");

    printf("\n%d sortierte Zahlen:\n", anzahl);
    printIntegerArray(ergebnisBubble, anzahl);

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

int fillRandomArray(int zahlen[], int anzahl)
{
    srand((unsigned int)time(NULL));

    for (int i = 0; i < anzahl; i++)
        zahlen[i] = rand() % 1000;

    return anzahl;
}

void copyIntegerArray(int quelle[], int ziel[], int anzahl)
{
    for (int i = 0; i < anzahl; i++)
        ziel[i] = quelle[i];
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

// Vergleichsfunktion fuer qsort: <0, 0 oder >0
int compareInts(const void *a, const void *b)
{
    int zahlA = *((const int *)a);
    int zahlB = *((const int *)b);

    return (zahlA > zahlB) - (zahlA < zahlB);
}

int arraysAreEqual(int ersteZahlen[], int zweiteZahlen[], int anzahl)
{
    for (int i = 0; i < anzahl; i++)
    {
        if (ersteZahlen[i] != zweiteZahlen[i])
            return 0;
    }

    return 1;
}

double sekunden(clock_t start, clock_t ende)
{
    return (double)(ende - start) / CLOCKS_PER_SEC;
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
