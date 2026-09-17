
#include <stdio.h>

int main(void)
{
    int a;

    /* Einzelne Zeichen nacheinander ausgeben */
    printf("Bitte ein Zeichen eingeben: ");
    a = getchar();
    putchar(a);
    printf("\n");          /* Zeilenumbruch / Linefeed */

    /* putchar() kann auch direkt mit dem ASCII-Code arbeiten */
    putchar(65);            /* 'A' */
    putchar(66);            /* 'B' */
    putchar(67);            /* 'C' */
    putchar('\n');

    return 0;
}
