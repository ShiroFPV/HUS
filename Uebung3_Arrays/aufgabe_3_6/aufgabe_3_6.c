#include <stdio.h>
#include <string.h>

#define NUMBER_OF_WORDS 10
#define MAX_CHARS_PER_WORD 20

const char wordList[NUMBER_OF_WORDS][MAX_CHARS_PER_WORD] = {
    "Widerstand",
    "Zinn",
    "Kupfer",
    "Blei",
    "Kondensator",
    "Transistor",
    "Programmieren",
    "Fernsteuerung",
    "Computer",
    "pragmatisch"
};

// Funktionsprototypen
int zaehleFehler(const char wort1[], const char wort2[]);

int main(void)
{
    char wort[MAX_CHARS_PER_WORD];
    int besterIndex = -1;
    int wenigsteFehler = MAX_CHARS_PER_WORD;

    printf("Rechtschreibfehler erkennen\n");
    printf("---------------------------\n");

    printf("\nGeben Sie ein Wort ein: ");
    if (scanf("%19s", wort) != 1)
        return 1;

    for (int i = 0; i < NUMBER_OF_WORDS; i++)
    {
        // Nur Woerter mit gleicher Buchstabenanzahl vergleichen
        if (strlen(wordList[i]) != strlen(wort))
            continue;

        int fehler = zaehleFehler(wordList[i], wort);
        if (fehler < wenigsteFehler)
        {
            wenigsteFehler = fehler;
            besterIndex = i;
        }
    }

    if (wenigsteFehler == 0)
        printf("Das Wort \"%s\" ist korrekt geschrieben.\n", wort);
    else if (besterIndex >= 0)
    {
        printf("Wort nicht im Woerterbuch gefunden.\n");
        printf("Meinten Sie \"%s\"? (%d falsche Buchstaben)\n", wordList[besterIndex], wenigsteFehler);
    }
    else
        printf("Wort nicht im Woerterbuch gefunden. Kein Vorschlag moeglich.\n");

    return 0;
}

//Funktionen

int zaehleFehler(const char wort1[], const char wort2[])
{
    int fehler = 0;

    for (int i = 0; wort1[i] != '\0'; i++)
        if (wort1[i] != wort2[i])
            fehler++;

    return fehler;
}
