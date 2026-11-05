#include <stdio.h>

#define MAX_LAENGE 100

// Funktionsprototypen
char *myStrCat(char *ziel, const char *quelle);
void removeNewline(char *text);

int main(void)
{
    char text1[2 * MAX_LAENGE];
    char text2[MAX_LAENGE];

    printf("Concatenation\n");
    printf("-------------\n");

    printf("\nErster Text:  ");
    if (fgets(text1, MAX_LAENGE, stdin) == NULL)
        return 1;
    removeNewline(text1);

    printf("Zweiter Text: ");
    if (fgets(text2, MAX_LAENGE, stdin) == NULL)
        return 1;
    removeNewline(text2);

    myStrCat(text1, text2);

    printf("\nResultat: %s\n", text1);

    return 0;
}

//Funktionen

char *myStrCat(char *ziel, const char *quelle)
{
    char *p = ziel;

    while (*p != '\0')
        p++;

    while ((*p++ = *quelle++) != '\0')
        ;

    return ziel;
}

void removeNewline(char *text)
{
    while (*text != '\0' && *text != '\n')
        text++;

    *text = '\0';
}
