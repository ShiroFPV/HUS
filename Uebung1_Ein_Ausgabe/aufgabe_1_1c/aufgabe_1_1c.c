#include <stdio.h>

int main(void)
{
    float zahl;

    printf("Bitte eine Fliesskommazahl eingeben: ");
    scanf("%f", &zahl);

    printf("Eingelesene Zahl: %.3f\n", zahl);

    return 0;
}
