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
* @brief Перечисление данных.
* @return Значение выбранной функции
*/
enum Choise
{
	Volume = 1,
	Area = 2
};

/**
* @brief Точка входа в программу 
* @return Код ошибки
*/
int main(void)
{
	setlocale(LC_ALL, "Russian");
	puts("Введите радиус шара");
	double radius = Input();
	enum Choise v, a;
	const v = Volume;
	const a = Area;
	puts("Введите 1(Объём шара) или 2(Площадь поверхности шара)");
	double inlet = Input();
	double bVolume = getVolume(radius);
	double bArea = getArea(radius);
	if (inlet == v)
		return printf_s("Объём шара % lf", bVolume);
	else if (inlet == a)
		return printf_s("Площадь поверхности шара %lf", bArea);
	else
		return puts("Ошибка ввода");
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