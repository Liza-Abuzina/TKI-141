#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include <errno.h>
#include <float.h>

/*
*@brief ��������� ������������ �����.
* @remarks ��� ������������ ����� ��������� ��������� ����������.
* @return ������������ �����.
*/
double input(void);

/**
*@brief �������� ���������.
* @param start - ��������� �������� ���������.
* @param end - �������� �������� ���������.
* @return �������� "true" � ������ ���������� �������.
*/
double checkinterval(const double start, const double end);

/**
*@brief �������� ����.
* @param ��� ������������ ����� ��������� ��������� ����������.
* @return �������� ���� � ������ ���������� �������.
*/
double checkstep(void);

/**
*@brief ���������� �������� �������.
* @param x - �������� ��������� �������.
* @return �������� ������� ��� �������� ��������� x.
*/
double getfunctionx(const double x);

/**
*@brief ���������� �������� �������.
* @param x - �������� ��������� �������.
* @param n - ������ ��������.
* @return �������� ������� ��� �������� ��������� x.
*/
double getrecurrfunctionx(const double x, const int n);

/**
*@brief ���������� ����� ��������������� ���� � 1 �� n - ��� �������.
* @param start - ��������� �������� ���������.
* @param end - �������� �������� ���������.
* @param eps - �������� �������� ����������.
* @return ����� ��������������� ���� � 1 �� n - ��� �������.
*/
double getsumm(const double start, const double end, const double eps);

/*
* @brief ����� ����� � ���������.
* @return ��� ������.
*/
int main(void)
{
    setlocale(LC_ALL, "Russian");
    const double eps = pow(10, -4);
    printf("������� ������ ���������: ");
    double start = input();
    printf("������� ����� ���������: ");
    double end = input();
    checkinterval(start, end);
    printf("������� ��� �� ���������: ");
    double step = checkstep();
    double x = start;
    printf("%-10s %-20s %-20sn", "x", "�������� �������", "�������� ��������������� ����\n");
    while (x <= end + DBL_EPSILON)
    {
        printf("%-10.2lf | %-20.10lf | %-20.10lf\n", x, getfunctionx(x), getsumm(start, end, eps));
        x += step;
    }
    return 0;
}

double input(void)
{
    double value = 0.0;
    if (scanf_s("%lf", &value) != 1)
    {
        errno = EIO;
        perror("������ ����� ��������� ��������: ");
        exit(EXIT_FAILURE);
    }
    return value;
}

double checkinterval(const double start, const double end)
{
    if (end - start < DBL_EPSILON)
    {
        errno = EIO;
        perror("������ ����� ��������� ��������: ");
        exit(EXIT_FAILURE);
    }
}

double checkstep(void)
{
    double step = input();
    if (step < DBL_EPSILON)
    {
        errno = EIO;
        perror("������ ����� ��������� ��������: ");
        exit(EXIT_FAILURE);
    }
    return step;
}

double getfunctionx(const double x)
{
    return pow(3, x);
}

double getrecurrfunctionx(const double x, const int n)
{
    return (x + log(3*x))/(n+1);
}

double getsumm(const double start, const double end, const double eps)
{
    double curr = start;
    double summ = 0.0;
    int n = 0;
    while (curr > eps - DBL_EPSILON)
    {
        summ += curr;
        curr *= getrecurrfunctionx(start, n);
        n++;
    }
    return summ;
}