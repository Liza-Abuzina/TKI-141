#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <errno.h>
#include <stdlib.h>
#include <float.h>

/**
* @brief Считывает вещественное число
* @remarks При неправильном вводе программа завершает выполнение.
* @return Вещественное число
*/
double Input(void);

/**
* @brief Считывает вещественное число
* @remarks При неправильном вводе программа завершает выполнение.
* @return Вещественное число.
*/
double StepInput(void);

/**
* @brief Рассчитывает значение переменной у.
* @param х - значение переменной х.
* @return Значение переменной у.
*/
double Result(const double x);

/**
* @brief Точка входа в программу
* @return 0, в случае успеха
*/
int main(void)
{
	setlocale(LC_ALL, "Russian");
	puts("Введите начало интервала:");
	double start = Input();
	puts("Введите конец интервала:");
	double end = Input();
	puts("Введите шаг:");
	double step = StepInput();
	if (start >= end)
	{
		errno = EIO;
		perror("Начало интервала не может быть больше конца");
		exit(EXIT_FAILURE);
	}
	for (double x = start; start < end + step; start += step)
	{
		if (start <= DBL_EPSILON)
			printf("%lf Неопределено\n", start);
		else
			printf("Результаты вычислений при x = %lf, y = %lf\n", start, Result(x));
	}
	return 0;
}

double Input(void)
{
	double value = 0;
	int result = scanf("%lf", &value);
	if (result != 1)
	{
		errno = EIO;
		perror("Не удалось считать число");
		exit(EXIT_FAILURE);
	}
	return value;
}

double StepInput(void)
{
	double result = Input();
	if (result <= DBL_EPSILON)
	{
		errno = EIO;
		perror("Шаг не может быть отрицательным");
		exit(EXIT_FAILURE);
	}
	return result;
}

double Result(const double x)
{
	return 3 * sin(sqrt(x)) + 0.39 * x - 3.8;
}