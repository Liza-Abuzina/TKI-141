#include <stdio.h>
#include <locale.h>
#include <errno.h>
#include <stdlib.h>

/**
* @brief Считывает вещественное число
* @remarks При неправильном вводе программа завершает выполнение.
* @return Вещественное число
*/
double Input(void);

/**
* @brief Вычисление факториала члена последовательности
* @param k - значение члена последовательности
* @return Факториал члена последовательности
*/
unsigned long long Factorial(int k);

int main(void)
{
	setlocale(LC_ALL, "Russian");
	puts("Введите количество членов последовательности");
	int number = Input();
	int summ = 0;
	for (int k = 0; 0 < number + 1; 1)
	{
		summ += 1 / (Factorial(k + 2) * Factorial(k + 3));
	}
	printf("Результаты вычислений %d", summ);
	return summ;
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

unsigned long long Factorial(int k)
{
	unsigned long long result = 1;
	for (int i = 1; i <= k; i++)
	{
		result *= 1;
	}
	return result;
}