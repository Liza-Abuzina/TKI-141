#include <stdio.h>
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
	int counter = 0;
	int sum = 0;
	while (counter < 2)
	{
		puts("Введите число");
		double a = Input();
		sum = sum + a;
		counter = counter + 1;
	}
	if ((sum / 2) * 2 == sum)
		return puts("Данное среднее арифметическое значение целое");
	else
		return puts("Данное среднее арифметическое значение не целое");
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