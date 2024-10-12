#include <stdio.h>
#include <locale.h>
#include <errno.h>
#include <stdlib.h>

/**
*@brief Рассчитывает выражение a по формуле
*@param a - Введённое пользователем число
*@param b - Введённое пользователем число
*@param c - Значение суммы a и b
*@return Рассчитаное значение a
*/
double getCheckArith(const double a, const double b, const double c);

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
	puts("Введите первое число");
	double a = Input();
	puts("Введите второе число");
	double b = Input();
	double c = a + b;
	double CheckArith = getCheckArith(a, b, c);
	puts("Ля ля %s", CheckArith);
	return 0;
}

double getCheckArith(const double a, const double b, const double c)
{
	if (c % 2 == 0)
		return puts("Kzzz");
	else
		return puts("dtttt");
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