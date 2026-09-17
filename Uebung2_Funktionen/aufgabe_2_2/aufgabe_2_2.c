#include <stdio.h>
#include <math.h>

void printDegMinSec(float angleRadian);
float convertAngleToDegrees(float angleRadian);
int getDegreesOnly(float angleDegrees);
int getMinutesOnly(float angleDegrees);
int getSecondsOnly(float angleDegrees);

int main() {
    float angleRadian;

    printf("Winkel in Radian eingeben: ");
    scanf("%f", &angleRadian);

    printDegMinSec(angleRadian);

    return 0;
}

void printDegMinSec(float angleRadian) {
    float angleDegrees = convertAngleToDegrees(angleRadian);
    int degrees = getDegreesOnly(angleDegrees);
    int minutes = getMinutesOnly(angleDegrees);
    int seconds = getSecondsOnly(angleDegrees);
    printf("%d Grad %d Minuten %d Sekunden\n", degrees, minutes, seconds);
}

float convertAngleToDegrees(float angleRadian) {
    return angleRadian * 180 / M_PI;
}

int getDegreesOnly(float angleDegrees) {
    return (int)angleDegrees;
}

int getMinutesOnly(float angleDegrees) {
    float restDegrees = angleDegrees - (int)angleDegrees;
    return (int)(restDegrees * 60);
}

int getSecondsOnly(float angleDegrees) {
    float restDegrees = angleDegrees - (int)angleDegrees;
    float restMinutes = restDegrees * 60 - (int)(restDegrees * 60);
    return (int)(restMinutes * 60);
}
