#include <stdio.h>
#include <locale.h>
#include <math.h>

/**
* @brief ����� ����� � ���������
* @return 0, � ������ ������
*/
int main(void)
{
	setlocale(LC_ALL, "Russian");
	for (double x = 2; x < 3.1; x += 0.1)
	{
		printf("���������� ���������� ��� x = %lf, y = %lf\n",x,3 * sin(sqrt(x)) + 0.39 * x - 3.8);
	}
	return 0;
}