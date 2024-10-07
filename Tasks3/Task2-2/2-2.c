#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <errno.h>
#include <stdlib.h>

/**
*@brief Рассчитывает выражение a по формуле
*@param a - Значение константы a
*@param x - Значение вводимого числа пользователем
*@return Рассчитаное значение a
*/
double getY(const double a, const double x);

/**
* @brief Считывает вещественное число
* @return Вещественное число
*/
double Input(void);

/**
* @brief Точка входа в программу =
* @return Код ошибки
*/
int main(void)
{
	setlocale(LC_ALL, "Russian");
	const double a = 2.5;
	puts("Введите число");
	double x = Input();
	double Y = getY(a, x);
	printf_s("Результат вычислений %lf", Y);
	return 0;
}

double getY(const double a, const double x)
{
	if (x > a)
		return x * cbrt(x - a);
	else
		return x * sin(a * x);
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