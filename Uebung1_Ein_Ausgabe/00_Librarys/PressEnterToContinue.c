#include <stdio.h>
#include "PressEnterToContinue.h"
#include "ClearInputBuffer.h"

void pressEnterToContinue(void)
{
    printf("Weiter mit Enter...");
    clearInputBuffer();
}
