#include <stdio.h>

int main(void)
{
    int i;
    int j;

    printf("Bitte geben Sie zwei ganze Zahlen ein: ");
    scanf("%d", &i);
    scanf("%d", &j);
    if (j == 0)
    {
        printf("Division durch 0 nicht erlaubt!\n");
        return 1;
    }
    else
    {
        printf("Quotient: %d\n", i / j);
    }
    return 0;
}
