#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <locale.h>
#include <float.h>
#include <math.h>

/**
* @brief Считывает вещественное число 
* @remarks При неправильном вводе программа завершает выполнение.
* @return Вещественное число
*/
double Input(void);

/**
* @brief Считывает вещественное число 
* @remarks При отрицательном значении ввода программа завершает выполнение
* @return Вещественное число
*/
double CheckInput(void);

/**
* @brief Получает на вход число k
* @return Рекурентное число с заданным k
*/
double GetReccurent(const double k);

/**
* @brief Считывает номер последнего члена последовательности
* @return Сумма рекурентных чисел
*/
double GetSumm(const double n);

/**
* @brief Вычисляет сумму членов последовательности, не меньших e
* @param e Пороговое значение
* @return Сумма членов последовательности, не меньших e
*/
double GetSummGreaterThanE(const double e);

/**
* @brief Точка входа в программу 
* @return Код ошибки
*/
int main(void)
{
	setlocale(LC_ALL, "Russian");
	puts("Введите номер последнего члена последовательности");
	double n = CheckInput();
	printf("Сумма при n = %lf равна %.18lf\n", n, GetSumm(n));
	puts("Введите пороговое число");
	double e = CheckInput();
	printf("Сумма членов последовательности, не меньших e = %lf равна %.18lf", e, GetSummGreaterThanE(e));
}

double Input(void)
{
	double value;
	int result = scanf("%lf", &value);
	if (result != 1)
	{
		errno = EIO;
		perror("Не удалось считать число");
		exit(EXIT_FAILURE);
	}
	return value;
}

double CheckInput(void)
{
	double value = Input();
	if (value <= DBL_EPSILON)
	{
		errno = EDOM;
		printf("Ошибка ввода числового значения");
		exit(EXIT_FAILURE);
	}
	return value;
}

double GetSumm(double n)
{
	double current = 1.0 / 12;
	double summ = current;
	for (int k = 1; k < n; k++)
	{
		current *= GetReccurent(k);
		summ += current;
	}
	return summ;
}

double GetReccurent(double k)
{
	return 1/((k + 2) * (k + 3));
}

double GetSummGreaterThanE(double e)
{
	double current = 1.0 / 12;
	double summ = 0.0;
	double k = 1.0;
	while (fabs(current) >= e)
	{
		summ += current;
		current *= GetReccurent(k);
		k++;
	}
	return summ;
}