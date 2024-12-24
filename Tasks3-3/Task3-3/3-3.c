#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include <errno.h>
#include <float.h>

/*
* @brief Считывает вещественное число.
* @remarks При неправильном вводе программа завершает выполнение.
* @return Вещественное число.
*/
double input(void);

/**
* @brief Считывает вещественное число
* @remarks При отрицательном значении ввода программа завершает выполнение
* @return Вещественное число
*/
double checkinputstart(void);

/**
* @brief Проверка интервала.
* @param start - начальное значение интервала.
* @param end - конечное значение интервала.
* @return Значение "true" в случае выполнения условия.
*/
double checkinterval(const double start, const double end);

/**
* @brief Проверка шага.
* @param При неправильном вводе программа завершает выполнение.
* @return Значение шага в случае выполнения условия.
*/
double checkstep(void);

/**
* @brief Вычисление значения функции.
* @param x - значение аргумента функции.
* @return Значение функции при значении аргумента x.
*/
double getfunctionx(const double x);

/**
*@brief Вычисление значения функции.
* @param x - значение аргумента функции.
* @param n - индекс элемента.
* @return Значение функции при значении аргумента x.
*/
double getrecurrfunctionx(const double x, const int n);

/**
* @brief Вычисление суммы функционального ряда с 1 по n - ный элемент.
* @param start - начальное значение интервала.
* @param end - конечное значение интервала.
* @param eps - заданная точность вычисления.
* @return Сумма функционального ряда с 1 по n - ный элемент.
*/
double getsumm(const double start, const double end, const double eps);

/*
* @brief Точка входа в программу.
* @return Код ошибки.
*/
int main(void)
{
    setlocale(LC_ALL, "Russian");
    const double eps = pow(10, -4);
    printf("Введите начало интервала: ");
    double start = checkinputstart();
    printf("Введите конец интервала: ");
    double end = input();
    checkinterval(start, end);
    printf("Введите шаг на интервале: ");
    double step = checkstep();
    double x = start;
    printf("%-10s %-20s %-20s", "x", "Значение функции", "Значение функционального ряда\n");
    while (x <= end + DBL_EPSILON)
    {
        printf("%-10.2lf | %-20.10lf | %-20.10lf\n", x, getfunctionx(x), getsumm(start, end, eps));
        x += step;
    }
    return 0;
}

double input(void)
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

double checkinputstart(void)
{
    double value = input();
    if (value <= DBL_EPSILON)
    {
        errno = EDOM;
        printf("Значение функционального ряда не существует на заданном начале интервала");
        exit(EXIT_FAILURE);
    }
    return value;
}

double checkinterval(const double start, const double end)
{
    if (end - start < DBL_EPSILON)
    {
        errno = EIO;
        perror("Ошибка ввода числового значения: ");
        exit(EXIT_FAILURE);
    }
}

double checkstep(void)
{
    double step = input();
    if (step < DBL_EPSILON)
    {
        errno = EIO;
        perror("Ошибка ввода числового значения: ");
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