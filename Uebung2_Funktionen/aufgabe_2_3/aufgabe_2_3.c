#include <stdio.h>
#include <math.h>

typedef enum { SIN, COS, TAN } TrigFunction;

void calcTrig(float angle, TrigFunction function);

int main() {
    float angle;
    int choice;

    printf("Winkel (Rad): ");
    scanf("%f", &angle);

    printf("Funktion (0=SIN, 1=COS, 2=TAN): ");
    scanf("%d", &choice);

    calcTrig(angle, choice);

    return 0;
}

void calcTrig(float angle, TrigFunction function) {
    float result;

    if (function == SIN) {
        result = sin(angle);
        printf("SIN(%.4f) = %.2f\n", angle, result);
    } else if (function == COS) {
        result = cos(angle);
        printf("COS(%.4f) = %.2f\n", angle, result);
    } else {
        result = tan(angle);
        printf("TAN(%.4f) = %.2f\n", angle, result);
    }
}
