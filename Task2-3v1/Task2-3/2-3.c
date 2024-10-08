#include <stdio.h>
#include <locale.h>
#include <errno.h>
#include <stdlib.h>

/**
*@brief ������������ ��������� a �� �������
*@param x - �������� ��������� ����� ������������� x
*@param b - �������� ��������� ����� ������������� b
*@return ����������� �������� a
*/
double getArithmetic(const double a,const double b);

/**
* @brief ��������� ������������ �����
* @return ������������ �����
*/
double Input(void);

/**
* @brief ����� ����� � ��������� =
* @return ��� ������
*/
int main(void)
{
	setlocale(LC_ALL, "Russian");
	puts("������� ������ �����");
	double a = Input();
	puts("������� ������ �����");
	double b = Input();
	double CheckArith = getArithmetic(a, b);

	printf_s("��������� ������� �������� ����� %lf", CheckArith);
	return 0;
}

double getArithmetic(const double a, const double b)
{
	return (a + b) / 2;
}

double Input(void)
{
	double value = 0;
	int result = scanf("%lf", &value);
	if (result != 1)
	{
		errno = EIO;
		perror("�� ������� ������� �����");
		exit(EXIT_FAILURE);
	}
	return value;
}