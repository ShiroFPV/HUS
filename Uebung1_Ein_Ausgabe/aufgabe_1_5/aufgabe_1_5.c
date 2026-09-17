#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(void)
{
    int i;
    bool doagain = false;
    
    do
    {
        printf("Bitte geben Sie eine Zahl ein: ");
        scanf("%d", &i);
        system("clear");
        if(i >= 99)
        {

            printf("Diese Zahl ist zu gross!\n");
            doagain = true;
        }
        else
            doagain = false;

    } 
    while (doagain);
    printf("Die letzte Ziffer der Zahl ist: %d\n", i % 10);
    return 0;
}