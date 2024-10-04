#include <stdio.h>
#include<locale.h>
#include <math.h>

/**
* @brief Рассчитывает площадь прямоугольника
* @param length длина прямоугольника
* @param coef коэффицент, позволяющий вычислить ширину прямоугольника
* @return Площадь прямоугольника
*/
double GetArea(const double length, const double coef);

/**
* @brief Рассчитывает периметр прямоугольника
* @param length длина прямоугольника
* @param coef коэффицент, позволяющий вычислить ширину прямоугольника
* @return Периметр прямоугольника
*/
double GetPerimetr(const double length, const double coef);

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
	puts("Введите длину прямоугольника");
	double length = Input();
	puts("Введите коэффицент");
	double coef = Input();
	double area = GetArea(length, coef);
	double perimetr = GetPerimetr(length, coef);
	printf_s("Площадь прямоугольника %lf", area);
	printf_s("Периметр прямоугольника %lf", perimetr);

	return 0;
}

double GetArea(const double length, const double coef)
{
	return length * (coef * length);
}
double GetPerimetr(const double length, const double coef)
{
	return (length + (coef * length)) * 2;
}
double Input(void)
{
	double value;
	scanf_s("%lf", &value);
	return value;
}