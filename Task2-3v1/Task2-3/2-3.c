#include <stdio.h>
#include <locale.h>
#include <errno.h>
#include <stdlib.h>

/**
*@brief Рассчитывает выражение a по формуле
*@param x - Значение вводимого числа пользователем x
*@param b - Значение вводимого числа пользователем b
*@return Рассчитаное значение a
*/
double getArithmetic(const double a,const double b);

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
	puts("Введите первое число");
	double a = Input();
	puts("Введите второе число");
	double b = Input();
	double CheckArith = getArithmetic(a, b);

	printf_s("Найденное среднее значение целое %lf", CheckArith);
	return 0;
}

double getArithmetic(const double a, const double b)
{
	return (a + b) / 2;
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