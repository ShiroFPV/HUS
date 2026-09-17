#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funktionsprototypen
int spielen(int gesuchteZahl);

int main() {
    int gesuchteZahl, versuche;

    srand((unsigned int)time(NULL));
    gesuchteZahl = 1 + rand() % 10;

    printf("Ratespiel\n");
    printf("---------\n");
    printf("Errate die Zahl zwischen 1 und 10!\n");

    versuche = spielen(gesuchteZahl);

    printf("\nRichtig! Du hast %d Versuche gebraucht.\n", versuche);

    return 0;
}

//Funktionen
int spielen(int gesuchteZahl) {
    int eingabe, versuche = 0;

    do {
        printf("\nDeine Vermutung: ");
        scanf("%d", &eingabe);
        while ((getchar()) != '\n');
        versuche++;

        if (eingabe < gesuchteZahl)
            printf("Zu klein!\n");
        else if (eingabe > gesuchteZahl)
            printf("Zu gross!\n");

    } while (eingabe != gesuchteZahl);

    return versuche;
}