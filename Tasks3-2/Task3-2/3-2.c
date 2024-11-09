#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <locale.h>
#include <float.h>

/**
* @brief Считывает вещественное число n
* @remarks При неправильном вводе программа завершает выполнение.
* @return Вещественное число
*/
double Input(void);

/**
* @brief Получает на вход число k
* @return Рекурентное число с заданным k
*/
double GetReccurent(double k);

/**
* @brief Считывает номер последнего члена последовательности
* @return Сумма рекурентных чисел
*/
double GetSumm(double n);

/**
* @brief Вычисляет сумму членов последовательности, не меньших e
* @param e Пороговое значение
* @return Сумма членов последовательности, не меньших e
*/
double GetSummGreaterThanE(double e);

/**
* @brief Точка входа в программу 
* @return Код ошибки
*/
int main(void)
{
	setlocale(LC_ALL, "Russian");
	puts("Введите номер последнего члена последовательности");
	double n = Input();
	printf("Сумма при n = %lf равна %.18lf\n", n, GetSumm(n));
	puts("Введите пороговое число");
	double e = Input();
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
	if (result <= DBL_EPSILON)
	{
		errno = EDOM;
		printf("Количество членов последовательности не может быть < 0");
		exit(EXIT_FAILURE);
	}
	return value;
}


double GetSumm(double n)
{
	double current = 1.0 / 12;
	double summ = 1.0 / 12;
	for (double k = 1; k < n; k++)
	{
		printf("current = %.18lf, k = %lf\n", current, k);
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
	double k = 0;
	while (current >= e)
	{
		summ += current;
		k++;
		current *= GetReccurent(k);
	}
	return summ;
}