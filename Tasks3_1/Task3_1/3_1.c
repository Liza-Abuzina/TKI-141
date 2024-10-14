#include <stdio.h>
#include <locale.h>
#include <math.h>

/**
* @brief Точка входа в программу
* @return 0, в случае успеха
*/
int main(void)
{
	setlocale(LC_ALL, "Russian");
	for (double x = 2; x < 3.1; x += 0.1)
	{
		printf("Результаты вычислений при x = %lf, y = %lf\n",x,3 * sin(sqrt(x)) + 0.39 * x - 3.8);
	}
	return 0;
}