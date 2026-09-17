#include "ClearInputBuffer.h"
#include <stdio.h>

int main(void)
{
    int i;
    float f;

    printf("Enter a Decimal number: ");
    scanf("%d", &i);
    printf("your input is: %d\n", i);
    clearInputBuffer();

    printf("Enter a Float number: ");
    scanf("%f", &f);
    printf("your input is: %f\n", f);
    clearInputBuffer();

    return 0;
}