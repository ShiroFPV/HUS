 #include <stdio.h>

int main(void)
{
	int produkte[11][11];

	for (int zeile = 0; zeile <= 10; zeile++)
	{
		for (int spalte = 0; spalte <= 10; spalte++)
		{
			produkte[zeile][spalte] = zeile * spalte;
		}
	}

	for (int zeile = 0; zeile <= 10; zeile++)
	{
		for (int spalte = 0; spalte <= 10; spalte++)
		{
			printf("%4d", produkte[zeile][spalte]);
		}
		printf("\n");
	}

	return 0;
}
