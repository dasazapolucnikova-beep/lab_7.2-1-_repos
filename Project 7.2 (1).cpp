#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Прототипи рекурсивних функцій
void CreateRow(int** a, const int rowNo, const int colNo, const int colCount, const int Low, const int High);
void CreateRows(int** a, const int rowNo, const int rowCount, const int colCount, const int Low, const int High);
void PrintRow(int** a, const int rowNo, const int colNo, const int colCount);
void PrintRows(int** a, const int rowNo, const int rowCount, const int colCount);
int MaxInCol(int** a, const int rowNo, const int colNo, const int rowCount, int max);
int SumMaxInOddColumns(int** a, const int colNo, const int rowCount, const int colCount);

int main()
{
    srand((unsigned)time(NULL));

    int k, n;
    cout << "k rows = "; cin >> k;
    cout << "n columns = "; cin >> n;

    // Динамічне виділення пам'яті під матрицю k x n
    int** a = new int* [k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    int Low = -10, High = 20;

    CreateRows(a, 0, k, n, Low, High);
    cout << "\nInitial matrix:\n";
    PrintRows(a, 0, k, n);

    // Запускаємо пошук з першого непарного стовпця (індекс 1)
    int sum = SumMaxInOddColumns(a, 1, k, n);
    cout << "Sum of max elements in odd columns: " << sum << endl;

    // Звільнення пам'яті
    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

// Рекурсивне створення одного рядка
void CreateRow(int** a, const int rowNo, const int colNo, const int colCount, const int Low, const int High)
{
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < colCount - 1)
        CreateRow(a, rowNo, colNo + 1, colCount, Low, High);
}

// Рекурсивне створення всіх рядків
void CreateRows(int** a, const int rowNo, const int rowCount, const int colCount, const int Low, const int High)
{
    CreateRow(a, rowNo, 0, colCount, Low, High);
    if (rowNo < rowCount - 1)
        CreateRows(a, rowNo + 1, rowCount, colCount, Low, High);
}

// Рекурсивне виведення одного рядка
void PrintRow(int** a, const int rowNo, const int colNo, const int colCount)
{
    cout << setw(5) << a[rowNo][colNo];
    if (colNo < colCount - 1)
        PrintRow(a, rowNo, colNo + 1, colCount);
    else
        cout << endl;
}

// Рекурсивне виведення всіх рядків
void PrintRows(int** a, const int rowNo, const int rowCount, const int colCount)
{
    PrintRow(a, rowNo, 0, colCount);
    if (rowNo < rowCount - 1)
        PrintRows(a, rowNo + 1, rowCount, colCount);
    else
        cout << endl;
}

// Рекурсивний пошук максимуму у заданому стовпці colNo
int MaxInCol(int** a, const int rowNo, const int colNo, const int rowCount, int max)
{
    if (a[rowNo][colNo] > max)
        max = a[rowNo][colNo];

    if (rowNo < rowCount - 1)
        return MaxInCol(a, rowNo + 1, colNo, rowCount, max);
    else
        return max;
}

// Рекурсивна сума максимумів по непарних стовпцях
int SumMaxInOddColumns(int** a, const int colNo, const int rowCount, const int colCount)
{
    if (colNo >= colCount)
        return 0;

    int maxCol = MaxInCol(a, 0, colNo, rowCount, a[0][colNo]);
    return maxCol + SumMaxInOddColumns(a, colNo + 2, rowCount, colCount);
}

