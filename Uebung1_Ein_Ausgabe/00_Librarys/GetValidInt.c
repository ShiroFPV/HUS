#include <stdio.h>
#include "GetValidInt.h"
#include "ClearInputBuffer.h"

int getValidInt(const char *prompt)
{
    int value;

    while (1)
    {
        printf("%s", prompt);

        if (scanf("%d", &value) == 1)
        {
            clearInputBuffer();
            return value;
        }

        printf("Ungueltige Eingabe, bitte eine Zahl eingeben.\n");
        clearInputBuffer();
    }
}
