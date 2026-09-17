#include <stdio.h>

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
                printf(" ⋅ ");
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
    printf("Enter the size of the grid: ");
    scanf("%d", &SIZE);

    int R = 0;
    int I = 0;
    printf("Enter the resistance in Ohm: ");
    scanf("%d", &R);
    printf("Enter the current in Ampere: ");
    scanf("%d", &I);

    if (R >= SIZE || I >= SIZE)
    {
        printf("The resistance or current is too high!\n");
        return 0;
    }

    printGrid(R, I);

    return 0;
}