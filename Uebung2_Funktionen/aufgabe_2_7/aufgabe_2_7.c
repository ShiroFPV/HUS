#include <stdio.h>
#include <math.h>

// Funktionsprototypen
int berechneAnzahlJahre(float startkapital, float endkapital, float zinsfuss);

int main() {
    float startkapital, endkapital, zinsfuss;
    int anzahlJahre;

    printf("Zinseszins\n");
    printf("----------\n");

    printf("\nStartkapital: ");
    scanf("%f", &startkapital);
    while ((getchar()) != '\n');

    printf("Gewuenschtes Endkapital: ");
    scanf("%f", &endkapital);
    while ((getchar()) != '\n');

    printf("Zinsfuss in %% (z.B. 1.2): ");
    scanf("%f", &zinsfuss);
    while ((getchar()) != '\n');

    anzahlJahre = berechneAnzahlJahre(startkapital, endkapital, zinsfuss);

    printf("\nAnzahl Jahre: %d\n", anzahlJahre);

    return 0;
}

//Funktionen
int berechneAnzahlJahre(float startkapital, float endkapital, float zinsfuss) {
    float n = log(endkapital / startkapital) / log(1.0f + zinsfuss / 100.0f);
    return (int)ceil(n);
}
