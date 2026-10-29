#include <stdio.h>
#include <string.h>

#define ANZAHL_WOERTER 5
#define MAX_LAENGE 50

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
