#include <stdio.h>
#include <string.h>

#define ANZAHL_WOERTER 5
#define MAX_LAENGE 50

/*
 * Wie strcmp() vergleicht:
 * - Zeichenweise nach ASCII-Code, bis ein Unterschied oder '\0' kommt.
 * - Gross-/Kleinbuchstaben: Grossbuchstaben (65-90) kommen vor
 *   Kleinbuchstaben (97-122), also "Zug" < "apfel".
 * - Zahlen (48-57) kommen vor allen Buchstaben, "123" < "Abc".
 * - Sonderzeichen liegen verstreut (z.B. ' ' = 32, '!' = 33, '_' = 95),
 *   Umlaute sind nicht im ASCII-Bereich und landen am Ende.
 * - Gleicher Wortanfang (Aarau, Appenzell): Erstes unterschiedliches Zeichen
 *   entscheidet ('a' < 'p'), also "Aarau" < "Appenzell".
 *   Ist ein Wort Anfang des anderen, kommt das kuerzere zuerst ("Bern" < "Berner").
 */

// Funktionsprototypen
void bubbleSort(char woerter[][MAX_LAENGE], int anzahl);

int main(void)
{
    char woerter[ANZAHL_WOERTER][MAX_LAENGE];

    printf("Woerter sortieren\n");
    printf("-----------------\n");

    for (int i = 0; i < ANZAHL_WOERTER; i++)
    {
        printf("Wort %d eingeben: ", i + 1);
        if (scanf("%49s", woerter[i]) != 1)
            return 1;
    }

    bubbleSort(woerter, ANZAHL_WOERTER);

    printf("\nSortiert:\n");
    for (int i = 0; i < ANZAHL_WOERTER; i++)
        printf("%s\n", woerter[i]);

    return 0;
}

//Funktionen

void bubbleSort(char woerter[][MAX_LAENGE], int anzahl)
{
    char temp[MAX_LAENGE];

    for (int i = 0; i < anzahl - 1; i++)
        for (int j = 0; j < anzahl - 1 - i; j++)
            if (strcmp(woerter[j], woerter[j + 1]) > 0)
            {
                strcpy(temp, woerter[j]);
                strcpy(woerter[j], woerter[j + 1]);
                strcpy(woerter[j + 1], temp);
            }
}
