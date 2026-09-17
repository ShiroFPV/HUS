#include <stdio.h>

// Funktionsprototypen
long fakultaet(int n);

int main() {
    int zahl;
    long ergebnis;

    printf("Fakultaet\n");
    printf("---------\n");

    printf("\nGeben Sie eine Zahl ein: ");
    scanf("%d", &zahl);
    while ((getchar()) != '\n');

    ergebnis = fakultaet(zahl);

    printf("%d! = %ld\n", zahl, ergebnis);

    return 0;
}

//Funktionen
long fakultaet(int n) {
    if (n <= 0)
        return 1;
    return n * fakultaet(n - 1);
}
