#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <stdbool.h>

/**
*@brief Нахождение соседних элементов с указанной суммой.
* @param array - массив
* @param k - размер массива
* @param summ - сумма элементов
* @return Число "1", если найдены соседние элементы с указанной суммой, иначе "0".
*/
int haspairwithsum(const int* array, const size_t n, const int summ);

/**
*@brief Массив
* @param array - массив
* @param n - размер массива
* @return Выводит индексы элементов массива, которые кратны 3.
*/
void printindicesdivisibleby3(const int* array, const size_t n);

/**
*@brief Массив
* @param array - массив
* @param n - размер массива
* @return Выводит пользователю массив
*/
void printarray(const int* array, const size_t n);

/**
*@brief Замена k элементов массива на значения с противоположным знаком.
* @param copy_array - копия массива.
* @param k - размер массива.
* @param n - размер массива.
* @return Изменённый массив.
*/
void replacelastk(int* copy_array, const size_t n, const size_t k);

/**
*@brief Заполнение массива n - количеством рандомных элементов в интервале.
* @param array - массив.
* @param n - размер массива.
* @param start - начало интервала.
* @param end - конец интервала.
* @return Заполненый массив.
*/
void fillarrayrandomly(int* array, const size_t n);

/**
*@brief Заполнение массива n - количеством элементов полученных от пользователя.
* @param array - массив
* @param n - размер массива
* @return Заполненый массив
*/
void fillarraymanually(int* array, const size_t n);

/**
*@brief Проверка корректности ввода интервала.
* @param start - начало интервала.
* @param end - конец интервала.
* @return Значение "true" в случае усепшной проверки.
*/
void checkinterval(int const start, int const end);

/**
*@brief Массив
* @param array - исходный массив
* @param n - размер массива
* @return Создание копии массива
*/
int* getcopyarray(const int* array, const int n);

/**
*@brief Проверка иницилизации массива.
* @param array - массив
* @return Значение "true" в случае усепшной проверки.
*/
void checkarray(const int* array);

/**
*@brief Массив
* @param n - размер массива
* @return Создание нового массива
*/
int* getnewarray(const int n);
/**
*@brief Считывает целочисленное значение.
* @remarks При неправильном вводе программа завершает выполнение.
* @return Целочисленное значение.
*/
int inputvalue(void);

/**
*@brief Считывает целочисленное значение.
* @remarks Проверяет полученное значение на ноль, при соответствии программа завершает выполнение.
* @return Целочисленное значение.
*/
int abovezero(void);

/**
*@brief Выбор исполняемой функции
* @brief Заполнить массив рандомными числами
* @brief Заполнить массив самостоятельно
*/
enum Choise
{
    Fillrandomly = 1,
    Fillmanually = 2,
};

/**
*@brief Точка входа в программу.
* @return 0, в случае успеха.
*/
int main(void)
{
    setlocale(LC_ALL, "Russian");
    printf("Введите размер массива: \n");
    size_t n = (size_t)abovezero();
    printf("Если вы хотите запонить массив рандомными числами, то нажмите (%d), иначе нажмите (%d): \n", Fillrandomly, Fillmanually);
    int choice = inputvalue();
    int* array = getnewarray(n);
    switch ((enum Choise)choice)
    {
    case Fillrandomly: fill_array_randomly(array, n);
        break;
    case Fillmanually: fill_array_manually(array, n);
        break;
    default: puts("Ошибка ввода номера операции.");
        return 1;
        break;
    }
    printf("Исходный массив: \n");
    printarray(array, n);
    printf("Индексы элементов, кратных 3: ");
    printindicesdivisibleby3(array, n);
    printf("Введите значение суммы элементов массива: \n");
    int summ = inputvalue();
    if (haspairwithsum(array, n, summ))
    {
        printf("Существуют соседние элементы с указанной суммой.\n");
    }
    else
    {
        printf("Соседние элементы с указанной суммой отсутствуют.\n");
    }
    int* copyarray = getcopyarray(array, n);
    printf("Введите количество последних элементов массива, которые нужно заменить на значения с противоположным знаком: \n");
    size_t k = (size_t)above_zero();
    replacelastk(copyarray, n, k);
    printf("Изменённый массив: \n");
    print_array(copyarray, n);
    free(array);
    free(copyarray);
    return 0;
}

void printarray(const int* array, const size_t n)
{
    checkarray(array);
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int haspairwithsum(const int* array, const size_t n, const int summ)
{
    checkarray(array);
    for (size_t i = 0; i < n - 1; i++)
    {
        if (array[i] + array[i + 1] == summ)
        {
            return true;
        }
    }
    return false;
}

void printindicesdivisibleby3(const int* array, const size_t n)
{
    checkarray(array);
    for (size_t i = 0; i < n; i++)
    {
        if (array[i] % 3 == 0 && array[i] != 0)
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void replacelastk(int* copy_array, const size_t n, const size_t k)
{
    checkarray(copy_array);
    for (size_t i = n - k; i < n; i++)
    {
        copy_array[i] = -copy_array[i];
    }
}

void fillarrayrandomly(int* array, const size_t n)
{
    checkarray(array);
    srand(time(NULL));
    printf("Введите начало интервала: \n");
    int start = inputvalue();
    printf("Введите конец интервала: \n");
    int end = inputvalue();
    checkinterval(start, end);

    for (size_t i = 0; i < n; i++)
    {
        array[i] = rand() % (end - start + 1) + start;
    }
}

void fillarraymanually(int* array, const size_t n)
{
    checkarray(array);
    for (size_t i = 0; i < n; i++)
    {
        printf("Введите элемент %zu: ", i + 1);
        scanf_s("%d", &array[i]);
    }
}

void checkinterval(int const start, int const end)
{
    if (start > end)
    {
        errno = EIO;
        perror("Ошибка ввода интервала: ");
        exit(EXIT_FAILURE);
    }
}

void checkarray(const int* array)
{
    if (array == NULL)
    {
        errno = EIO;
        perror("Массив не инициализирован: ");
        exit(EXIT_FAILURE);
    }
}

int* getcopyarray(const int* array, const int n)
{
    checkarray(array);
    int* copyarray = (int*)malloc(n * sizeof(int));
    checkarray(copyarray);

    for (size_t i = 0; i < n; i++)
    {
        copyarray[i] = array[i];
    }
    return copyarray;
}

int* getnewarray(const int n)
{
    int* array = (int*)malloc(n * sizeof(int));
    checkarray(array);
    return array;
}

int inputvalue(void)
{
    int value = 0;
    if (scanf_s("%d", &value) != 1)
    {
        errno = EIO;
        perror("Ошибка ввода числового значения: ");
        exit(EXIT_FAILURE);
    }
    return value;
}

int abovezero(void)
{
    int value = inputvalue();
    if (value <= 0)
    {
        errno = EIO;
        perror("Ошибка ввода числового значения (оно не может быть меньше или равный нулю): ");
        exit(EXIT_FAILURE);
    }
    return value;
}