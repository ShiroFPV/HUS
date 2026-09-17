#include <stdio.h>
#include <stdlib.h>

int SIZE = 0;

void printGrid(int x, int y)
{
    for (int row = SIZE - 1; row >= 0; row--)
    {
        printf("%2d |", row);
        for (int col = 0; col < SIZE; col++)
        {
            if (col == x && row == y)
                printf(" * ");
            else
                printf(" . ");
        }
        printf("\n");
    }

    printf("   +");
    for (int col = 0; col < SIZE; col++)
        printf("---");
    printf("\n");

    printf("    ");
    for (int col = 0; col < SIZE; col++)
        printf("%2d ", col);
    printf("\n");
}

int main(void)
{
    char choice;

    do {
        system("clear");
        printf("Enter the size of the gridm: ");
        scanf("%d", &SIZE);

        int R = 0;
        int I = 0;
        printf("Enter the resistance in Ohm: ");
        scanf("%d", &R);
        printf("Enter the current in Ampere: ");
        scanf("%d", &I);
        system("clear");
        if (R >= SIZE || I >= SIZE)
        {
            printf("The resistance or current is too high!\n");
        }
        else
        {
            printGrid(R, I);
        }

        printf("Again? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');
    system("clear");
    return 0;
}
