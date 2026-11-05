#include <stdio.h>

int main(void)
{
    int zahl = 42;
    int *pZahl = NULL;

    printf("Prinzip Pointer\n");
    printf("---------------\n");

    pZahl = &zahl;

    printf("\nReferenzieren (pZahl = &zahl)\n");
    printf("Wert von zahl:              %d\n", zahl);
    printf("Adresse von zahl (%%p):      %p\n", (void *)&zahl);
    printf("Adresse von zahl (%%lx):     %lx\n", (unsigned long)&zahl);

    printf("\nInhalt der Pointervariable\n");
    printf("Wert von pZahl (%%p):        %p\n", (void *)pZahl);
    printf("Wert von pZahl (%%lx):       %lx\n", (unsigned long)pZahl);
    printf("Adresse von pZahl selbst:   %p\n", (void *)&pZahl);

    printf("\nDereferenzieren (*pZahl)\n");
    printf("Wert von *pZahl:            %d\n", *pZahl);

    *pZahl = 99;
    printf("\nNach *pZahl = 99\n");
    printf("Wert von zahl:              %d\n", zahl);
    printf("Wert von *pZahl:            %d\n", *pZahl);

    return 0;
}
