#include <stdio.h>

int main(void)
{
	double temperaturen[3];
	double summe = 0.0;

	printf("Temperatur morgens: ");
	scanf("%lf", &temperaturen[0]);

	printf("Temperatur mittags: ");
	scanf("%lf", &temperaturen[1]);

	printf("Temperatur abends: ");
	scanf("%lf", &temperaturen[2]);

	for (int i = 0; i < 3; i++)
	{
		summe += temperaturen[i];
	}

	printf("Durchschnittstemperatur: %.2f Grad Celsius\n", summe / 3.0);

	return 0;
}