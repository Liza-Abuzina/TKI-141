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
double checkstep(void);

/*
* @brief Рассчитывает значение переменной у.
* @param х - значение переменной х.
* @return Значение переменной у.
*/
double result(const double x);

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
	double step = checkstep();
	for (double x = start; start < end + step; start += step)
	{
		if (x == DBL_EPSILON)
			printf("%lf Неопределено\n", x);
		else
			printf("Результаты вычислений при x = %lf, y = %lf\n", start, 3 * sin(sqrt(start)) + 0.39 * start - 3.8);
	}
	return 0;
}

double result(const double x)
{
	return 3 * sin(sqrt(x)) + 0.39 * x - 3.8;
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

double checkstep(void)
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