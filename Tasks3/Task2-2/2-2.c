#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <errno.h>
#include <stdlib.h>

/**
* @brief Считывает вещественное число
* @return Вещественное число
*/
double Input(void);

/**
* @brief Точка входа в программу 
* @return Код ошибки
*/
int main(void)
{
	setlocale(LC_ALL, "Russian");
	const double a = 2.5;
	puts("Введите число");
	double x = Input();
	if (x > a)
		return printf("Результат вычислений %lf", x * cbrt(x - a));
	else
		return printf("Результат вычислений %lf", x * sin(a * x));
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