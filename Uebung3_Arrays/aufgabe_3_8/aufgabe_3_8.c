#include <stdio.h>
#include <math.h>

#define ANZAHL_ZEILEN 3

#define U_SOLL 12.0
#define I_SOLL 1.8
#define TOLERANZ 0.10
#define T_MAX 35.0

const char input[ANZAHL_ZEILEN][80] = {
    "DEV=PSU-03; U=12.05V; I=1.84A; T=32.6C",
    "DEV=LAB-12; U=11.01V; I=1.70A; T=25.0C",
    "DEV=PSU-99; U=13.1V; I=0.00A; T=27.4C"
};

// Funktionsprototypen
int inToleranz(double wert, double soll, double toleranz);

int main(void)
{
    char typ[20];
    double U = 0.0;
    double I = 0.0;
    double T = 0.0;

    for (int i = 0; i < ANZAHL_ZEILEN; i++)
    {
        if (sscanf(input[i], "DEV=%19[^;]; U=%lfV; I=%lfA; T=%lfC", typ, &U, &I, &T) != 4)
        {
            printf("Zeile %d: Parse-Fehler\n", i + 1);
            continue;
        }

        int ok = inToleranz(U, U_SOLL, TOLERANZ) && inToleranz(I, I_SOLL, TOLERANZ) && T < T_MAX;

        printf("%s %s\n", typ, ok ? "PASS" : "FAIL");
    }

    return 0;
}

//Funktionen

int inToleranz(double wert, double soll, double toleranz)
{
    return fabs(wert - soll) <= soll * toleranz;
}
