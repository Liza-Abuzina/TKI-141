#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <locale.h>

/**
*@brief ������������ ��������� a �� �������
*@param radius - �������� ������� ����
*@return ����������� �������� a
*/
double getVolume(const double radius);

/**
*@brief ������������ ��������� a �� �������
*@param radius - �������� ������� ����
*@return ����������� �������� a
*/
double getArea(const double radius);

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
	puts("������� ������ ����");
	double radius = Input();
	double bVolume = getVolume(radius);
	double bArea = getArea(radius);
	printf_s("����� ���� %lf\n", bVolume);
	printf_s("������� ����������� ���� %lf", bArea);
	return 0;
}

double getVolume(const double radius)
{
	return (4 / 3) * M_PI * pow(radius, 3);
}

double getArea(const double radius)
{
	return 4 * M_PI * pow(radius, 2);
}

double Input(void)
{
	double value;
	scanf_s("%lf", &value);
	return value;
}