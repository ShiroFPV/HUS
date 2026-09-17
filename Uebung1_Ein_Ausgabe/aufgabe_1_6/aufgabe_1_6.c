#include <stdio.h>

int main(void)
{
    int voltage;
    char again;

    do {
        printf("Measurement Value in Volts: ");
        scanf("%d", &voltage);

        if (voltage <= 2) {
            printf("The voltage is too low!\n");
        } else if (voltage <= 20) {
            printf("The voltage is low!\n");
        } else if (voltage <= 200) {
            printf("The voltage is high!\n");
        } else {
            printf("The voltage is too high!\n");
        }

        printf("Do another measurement? (y/n): ");
        scanf(" %c", &again);

    } while (again == 'y' || again == 'Y');

    return 0;
}