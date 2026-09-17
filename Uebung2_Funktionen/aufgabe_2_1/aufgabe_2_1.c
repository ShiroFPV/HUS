#include <stdio.h>
#include <math.h>

float convertAngle(float angleIn, char unitOfAngle);
float convertGradToRad(float angleInGrad);
float convertRadToGrad(float angleInRad);

int main() {
    float angleIn, convertedAngle;
    char unitOfAngle;

    printf("Winkel eingeben, abschliessen mit g(Grad) oder r(Rad): ");
    scanf("%f %c", &angleIn, &unitOfAngle);

    convertedAngle = convertAngle(angleIn, unitOfAngle);

    if (unitOfAngle == 'g')
        printf("In Rad: %8.2f Rad\n", convertedAngle);
    else
        printf("In Grad: %8.2f Grad\n", convertedAngle);

    return 0;
}

float convertGradToRad(float angleInGrad) {
    return angleInGrad * M_PI / 180;
}

float convertRadToGrad(float angleInRad) {
    return angleInRad * 180 / M_PI;
}

float convertAngle(float angleIn, char unitOfAngle) {
    if (unitOfAngle == 'g')
        return convertGradToRad(angleIn);
    else
        return convertRadToGrad(angleIn);
}