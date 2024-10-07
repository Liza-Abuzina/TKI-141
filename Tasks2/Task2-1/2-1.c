#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <locale.h>
#include <errno.h>
#include <stdlib.h>

/**
*@brief Рассчитывает выражение a по формуле
*@param radius - Значение радиуса шара
*@return Рассчитаное значение a
*/
double getVolume(const double radius);

/**
*@brief Рассчитывает выражение a по формуле
*@param radius - Значение радиуса шара
*@return Рассчитаное значение a
*/
double getArea(const double radius);

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
	puts("Введите радиус шара");
	double radius = Input();
	double bVolume = getVolume(radius);
	double bArea = getArea(radius);
	printf_s("Объём шара %lf\n", bVolume);
	printf_s("Площадь поверхности шара %lf", bArea);
	return 0;
}

double getVolume(const double radius)
{
	return (4 / 3) * M_PI * pow(radius, 3);
}

double getArea(const double radius)
{
	return 4 * M_PI * pow(radius, 2);
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