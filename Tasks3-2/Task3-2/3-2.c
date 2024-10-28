#include <stdio.h>
#include <locale.h>
#include <errno.h>
#include <stdlib.h>

int GetInt(void);

size_t GetNonNegativeInt(void);

double GetSum(size_t count);

double GetReccurent(size_t k);

int main(void)
{
	setlocale(LC_ALL, "Russian");
	puts("Введите количество членов последовательности");
	size_t count = GetNonNegativeInt();
	printf("Сумма последовательности из %zu элементов равна %.18lf", count, GetSum(count));
	return EXIT_SUCCESS;
}

int GetInt(void)
{
	int value = 0;
	int result = scanf("%d", &result);
	if (result != 1)
	{
		errno = EIO;
		printf("Не удалось считать число");
		exit(EXIT_FAILURE);
	}
	return value;
}

size_t GetNonNegativeInt(void)
{
	int value = GetInt();
	if (value <= 0)
	{
		errno = EDOM;
		printf("Количество членов последовательности не может быть < 0");
		exit(EXIT_FAILURE);
	}
	return (size_t)value;
}

double GetSum(size_t count)
{
	double summ = 0;
	double current = 1.0 / 12;
	for (size_t k = 0; k <= count; ++k)
	{
		printf("current = %.18lf, k = %zu\n", current, k);
		summ += current;
		current *= GetReccurent(k);
	}
	return summ;
}

double GetReccurent(size_t k) 
{
	return 1.0 / ((k + 2) * (k + 3));
}