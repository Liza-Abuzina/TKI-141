#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <stdbool.h>

/**
* @brief Вычисляет сумму нечетных элементов массива
* @param array - указатель на массив целых чисел
* @param n - размер массива
* @return Сумма нечетных элементов массива
*/
int sumofoddelements(int* array, const size_t n);

/**
* @brief Печатает индексы элементов массива, которые больше заданного значения A
* @param array - указатель на массив целых чисел
* @param n - размер массива
* @param A - значение, по которому производится сравнение
*/
void printindicesgreaterthana(int* array, const size_t n, int A);

/**
* @brief Заменяет второй элемент массива максимальным отрицательным элементом
* @param array - указатель на массив целых чисел
* @param n - размер массива
*/
void replacesecondelementwithmaxnegative(int* array, const size_t n);

/**
* @brief Массив
* @param array - массив
* @param n - размер массива
* @return Выводит пользователю массив
*/
void printarray(const int* array, const size_t n);

/**
* @brief Заполнение массива n - количеством рандомных элементов в интервале.
* @param array - массив.
* @param n - размер массива.
* @return Заполненый массив.
*/
void fillarrayrandomly(int* array, const size_t n);

/**
* @brief Заполнение массива n - количеством элементов полученных от пользователя.
* @param array - массив
* @param n - размер массива
* @return Заполненый массив
*/
void fillarraymanually(int* array, const size_t n);

/**
* @brief Проверка корректности ввода интервала.
* @param start - начало интервала.
* @param end - конец интервала.
* @return Значение "true" в случае усепшной проверки.
*/
void checkinterval(int const start, int const end);

/**
* @brief Проверка иницилизации массива.
* @param array - массив
* @return Значение "true" в случае усепшной проверки.
*/
void checkarray(const int* array);

/**
* @brief Массив
* @param n - размер массива
* @return Создание нового массива
*/
int* getnewarray(const int n);
/**
* @brief Считывает целочисленное значение.
* @remarks При неправильном вводе программа завершает выполнение.
* @return Целочисленное значение.
*/
int inputvalue(void);

/**
* @brief Считывает целочисленное значение.
* @remarks Проверяет полученное значение на ноль, при соответствии программа завершает выполнение.
* @return Целочисленное значение.
*/
int abovezero(void);

/**
* @brief Выбор исполняемой функции
* @brief Заполнить массив рандомными числами
* @brief Заполнить массив самостоятельно
*/
enum Choise
{
    Fillrandomly = 1,
    Fillmanually = 2,
};

/**
* @brief Точка входа в программу.
* @return 0, в случае успеха.
*/
int main(void)
{
    setlocale(LC_ALL, "Russian");
    printf("Введите размер массива: ");
    size_t n = (size_t)abovezero();
    printf("Если вы хотите заполнить массив рандомными числами, то введите (%d), иначе (%d): ", Fillrandomly, Fillmanually);
    int choice = inputvalue();
    int* array = getnewarray(n);
    switch ((enum Choise)choice)
    {
    case Fillrandomly:
        fillarrayrandomly(array, n);
        break;
    case Fillmanually:
        fillarraymanually(array, n);
        break;
    default:
        puts("Ошибка ввода номера операции.");
        free(array); 
        return 1;
    }
    printf("Исходный массив: \n");
    printarray(array, n);
    int sumodd = sumofoddelements(array, n);
    printf("Сумма нечетных элементов: %d ", sumodd);
    printf("Введите число A: ");
    int A = inputvalue();
    printindicesgreaterthana(array, n, A);
    replacesecondelementwithmaxnegative(array, n);
    printf("Массив после замены второго элемента:\n");
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    free(array);
    return 0;
}

int sumofoddelements(int* array, const size_t n)
{
    int sum = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (array[i] % 2 != 0)
        {
            sum += array[i];
        }
    }
    return sum;
}

void printindicesgreaterthana(int* array, const size_t n, int A)
{
    printf("Индексы элементов больше %d: ", A);
    int found = 0;
    for (size_t i = 0; i < n; i++) 
    {
        if (array[i] > A) 
        {
            printf("Индекс элемента, большего чем %d: %zu", A, i);
            found = 1; 
        }
    }
    if (!found) 
    {
        printf("Нет элементов, больших чем %d.", A);
    }
}
void replacesecondelementwithmaxnegative(int* array, const size_t n)
{
    int maxnegative = -1000;
    for (size_t i = 0; i < n; i++)
    {
        if (array[i] < 0 && array[i] > maxnegative)
        {
            maxnegative = array[i];
        }
    }
    if (maxnegative < 0 && n > 1)
    {
        array[1] = maxnegative;
    }
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

void fillarrayrandomly(int* array, const size_t n)
{
    checkarray(array);
    srand(time(NULL));
    printf("Введите начало интервала: ");
    int start = inputvalue();
    printf("Введите конец интервала: ");
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
        perror("Ошибка ввода числового значения (оно не может быть меньше или равным нулю): ");
        exit(EXIT_FAILURE);
    }
    return value;
}