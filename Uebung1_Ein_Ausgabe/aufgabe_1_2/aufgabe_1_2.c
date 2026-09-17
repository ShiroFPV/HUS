#include <stdio.h>

int main(void)
{
    double zahl1 = 34.67;
    double zahl2 = -3.78;
    double zahl3 = 88.01;
    double zahl4 = 9.33;

    double summe      = zahl1 + zahl2 + zahl3 + zahl4;
    double mittelwert = summe / 4.0;

    printf("Summe und Mittelwert:\n\n");
    printf("\t|--------------|---------|\n");
    printf("\t|Zahl 1      = |%9.2f|\n", zahl1);
    printf("\t|Zahl 2      = |%9.2f|\n", zahl2);
    printf("\t|Zahl 3      = |%9.2f|\n", zahl3);
    printf("\t|Zahl 4      = |%9.2f|\n", zahl4);
    printf("\t|--------------|---------|\n");
    printf("\t|Summe       = |%9.2f|\n", summe);
    printf("\t|              |   ======|\n");
    printf("\t|--------------|---------|\n");
    printf("\t|Mittelwert  = |%9.3f|\n", mittelwert);
    printf("\t|              |   ======|\n");
    printf("\t|--------------|---------|\n");
    return 0;
}