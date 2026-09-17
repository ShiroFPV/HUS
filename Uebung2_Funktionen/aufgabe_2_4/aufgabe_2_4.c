#include <stdio.h>

void zeichenAusgeben(char zeichen, int anzahl);

int main() {
    char zeichen;
    int anzahl;

    printf("Zeichen eingeben: ");
    scanf("%c", &zeichen);

    printf("Anzahl eingeben: ");
    scanf("%d", &anzahl);

    zeichenAusgeben(zeichen, anzahl);

    return 0;
}

void zeichenAusgeben(char zeichen, int anzahl) {
    for (int i = 0; i < anzahl; i++)
        putchar(zeichen);
    printf("\n");
}
