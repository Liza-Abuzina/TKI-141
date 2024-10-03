#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

/**
*@brief Рассчитывает выражение a по формуле
*@param x - Значение константы x
*@param y - Значение константы y
*@param z - Значение константы z
*@return Рассчитаное значение a
*/
double getA(const double x, const double y, const double z);

/**
*@brief Рассчитывает выражение a по формуле
*@param x - Значение константы x
*@param y - Значение константы y
*@param z - Значение константы z
*@return Рассчитаное значение a
*/
double getB(const double x, const double y, const double z);

/**
*@brief Точка входа в программу
*@return 0, в случае успеха
*/

int main()
{
	const double x = 1.426;
	const double y = -1.22;
	const double z = 3.5;
	printf("a = %f\nb = %f", getA(x, y, z), getB(x, y, z));
	return 0;
}

double getA(const double x, const double y, const double z)
{
	return (2 * cos(x - (M_PI / 6))) / (0.5 + pow(sin(y), 2));
}

double getB(const double x, const double y, const double z)
{
	return 1 + (pow(z, 2)) / (3 + (pow(z, 2) / 5));
}
