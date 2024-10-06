#include <stdio.h>
#include <locale.h>
#include <math.h>

/**
*@brief Рассчитывает выражение a по формуле
*@param mass - Значение массы пули
*@param velocity - Значение скорости пули
*@return Рассчитаное значение a
*/
double getEnergy(const double mass, const double velocity);

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
	puts("Введите массу пули");
	double mass = Input();
	puts("Введите скорость пули");
	double velocity = Input();
	double kEnergy = getEnergy(mass, velocity);
	printf_s("Кинетическая энергия пули %lf", kEnergy);
	return 0;
}

double getEnergy(const double mass, const double velocity)
{
	return (mass * pow(velocity, 2)) / 2;
}

double Input(void)
{
	double value;
	scanf_s("%lf", &value);
	return value;
}