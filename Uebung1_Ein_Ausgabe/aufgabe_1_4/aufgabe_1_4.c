#include <stdio.h>

int main(void)
{
    int i;
    
    printf("Bitte geben Sie eine ganze Zahl ein: ");
    scanf("%d", &i);
    printf("Die letzte Ziffer der eingegebenen Zahl ist: ");
    printf("%d\n", i % 10);

    return 0;
}