#include <stdio.h>
#include "ClearInputBuffer.h"

void clearInputBuffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
