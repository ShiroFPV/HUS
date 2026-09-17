#include <stdio.h>

int main(void)
{
    int i;
    
    printf("Bitte geben Sie eine 2 stellige Zahl ein: ");
    scanf("%d", &i);
    int erste_ziffer = i / 10;
    int zweite_ziffer = i % 10;
    printf("Die Zahl mit getauschten Ziffern ist: %d%d\n", zweite_ziffer, erste_ziffer);

    return 0;
}