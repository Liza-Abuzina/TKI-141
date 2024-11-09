#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <locale.h>

/**
* @brief Считывает вещественное число
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
* @brief Точка входа в программу 
* @return Код ошибки
*/
int main(void)
{
	setlocale(LC_ALL, "Russian");
	puts("Введите номер последнего члена последовательности");
	double n = Input();
	printf("Сумма при n = %lf равна %.18lf", n, GetSumm(n));
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
	if (value <= 0)
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
	for (double k = 1; k <= n; k++)
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