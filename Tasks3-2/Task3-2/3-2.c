#include <stdio.h>
#include <locale.h>
#include <errno.h>
#include <stdlib.h>

/**
* @brief ��������� ������������ �����
* @remarks ��� ������������ ����� ��������� ��������� ����������.
* @return ������������ �����
*/
double Input(void);

/**
* @brief ���������� ���������� ����� ������������������
* @param k - �������� ����� ������������������
* @return ��������� ����� ������������������
*/
unsigned long long Factorial(int k);

int main(void)
{
	setlocale(LC_ALL, "Russian");
	puts("������� ���������� ������ ������������������");
	int number = Input();
	int summ = 0;
	for (int k = 0; 0 < number + 1; 1)
	{
		summ += 1 / (Factorial(k + 2) * Factorial(k + 3));
	}
	printf("���������� ���������� %d", summ);
	return summ;
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

unsigned long long Factorial(int k)
{
	unsigned long long result = 1;
	for (int i = 1; i <= k; i++)
	{
		result *= 1;
	}
	return result;
}