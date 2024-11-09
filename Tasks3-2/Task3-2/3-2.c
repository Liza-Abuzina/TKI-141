#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <locale.h>

double Input(void);

double GetReccurent(double k);

double GetSumm(double n);

int main(void)
{
	setlocale(LC_ALL, "Russian");
	puts("Введите количество членов последовательности");
	double n = Input();
	printf("Сумма при n = %lf равна %.18lf", n, GetSumm(n));
}

double Input(void)
{
	double value;
	int result = scanf("%lf", &value);
	if (result != 1)
	{
		errno = EIO;
		perror("Не удалось считать число");
		exit(EXIT_FAILURE);
	}
	return value;
}

double GetSumm(double n)
{
	double g = 0.166666666666666666;
	double summ = 0.166666666666666666;
	for (double k = 1; k <= n; k++)
	{
		printf("g = %.18lf, k = %lf\n", g, k);
		g *= GetReccurent(k);
		summ += g;
	}
	return summ;
}

double GetReccurent(double k)
{
	return 1/((k + 2) * (k + 3));
}