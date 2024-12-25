#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <stdbool.h>

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
* @return Значение "true" в случае успешной проверки.
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
* @brief Проверяет, содержит ли переданное целое число хотя бы одну цифру 1
* @param num - Целое число, которое будет проверяться
* @return 1, если число содержит цифру "1", и 0 в противном случае
*/
bool containsdigitone(int num);

/**
* @brief Вставляет значение K перед каждым элементом массива, который содержит цифру 1. При этом размер массива увеличивается
* @param array - Указатель на массив целых чисел
* @param n - Указатель на переменную, хранящую текущий размер массива
* @param K - Значение, которое будет вставлено перед элементами, содержащими цифру 1
* @return Указатель на новый массив с вставленными значениями
*/
int* insertbeforedigitone(int* array, size_t* n, int K);

/**
* @brief Заполняет массив A значениями, основанными на значениях из массива D
* @param D - Указатель на массив целых чисел
* @param A - Указатель на массив целых чисел, который будет заполнен новыми значениями
* @param n - Размер массива D
*/
void createarraya(const int* D, int* A, size_t n);

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
    printf("Массив после замены второго элемента:\n");
    printarray(array, n);
    printf("Введите число K: ");
    int K = inputvalue();
    array = insertbeforedigitone(array, &n, K);
    printf("Массив после вставки K перед элементами, содержащими цифру 1:\n");
    printarray(array, n);
    int* A = getnewarray(n);
    createarraya(array, A, n);
    printf("Массив A:\n");
    printarray(A, n);
    free(array);
    free(A);
    return 0;
}

void replacesecondelementwithmaxnegative(int* array, const size_t n)
{
    checkarray(array);
    size_t i = 0;
    size_t maxnegative = 0;
    while ((i < n) && (array[i] > 0))
    {
        ++i;
    }
    return i;
    size_t maxnegative = array[i];
    if (i != n)
    {
        for (size_t i; i < n; i++)
        {
            if (array[i] < 0 && array[i] > maxnegative)
            {
                maxnegative = array[i];
            }
        }
        if (n > 1)
        {
            array[1] = maxnegative;
        }
    }
    else
    {
        printf("В массиве нет отрицательных чисел");
    }
    return array;
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

bool containsdigitone(int num) 
{
    num = abs(num);
    while (num > 0) 
    {
        if (num % 10 == 1) 
        {
            return true;
        }
        num /= 10;
    }
    return false;
}

int* insertbeforedigitone(int* array, size_t* n, int K) 
{
    for (size_t i = 0; i < *n; i++) 
    {
        if (containsdigitone(array[i])) 
        {
            *n += 1;
            array = realloc(array, (*n) * sizeof(int));
            if (array == NULL)
            {
                perror("Ошибка выделения памяти: ");
                exit(EXIT_FAILURE);
            }
            for (size_t j = *n - 1; j > i ; j--) 
            {
                array[j] = array[j - 1];
            }
            array[i] = K;
            i++;
        }
    }
    return array;
}

void createarraya(const int* D, int* A, size_t n) 
{
    for (size_t i = 0; i < n; i++) 
    {
        if (i % 2 == 0) 
        {
            A[i] = D[i] * D[i]; 
        }
        else 
        {
            A[i] = D[i] / (i + 1); 
        }
    }
}