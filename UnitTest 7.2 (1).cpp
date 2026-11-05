#include "pch.h"
#include "CppUnitTest.h"
#include "../Project 7.2 (1)/Project 7.2 (1).cpp" // Підключення основного файлу з функціями

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest721
{
	TEST_CLASS(UnitTest721)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			const int k = 3; // кількість рядків
			const int n = 4; // кількість стовпців

			// Динамічне виділення пам'яті під двовимірний масив k x n
			int** a = new int* [k];
			for (int i = 0; i < k; i++) {
				a[i] = new int[n];
			}

			// Наповнення матриці тестовими значеннями:
			// Стовпець 0 (парний):   [ 1,  2, 9]  -> Максимум = 9
			// Стовпець 1 (непарний): [10,  4, 3]  -> Максимум = 10
			// Стовпець 2 (парний):   [ 5,  1, 6]  -> Максимум = 6
			// Стовпець 3 (непарний): [-3, 12, 0]  -> Максимум = 12
			a[0][0] = 1;  a[0][1] = 10; a[0][2] = 5; a[0][3] = -3;
			a[1][0] = 2;  a[1][1] = 4;  a[1][2] = 1; a[1][3] = 12;
			a[2][0] = 9;  a[2][1] = 3;  a[2][2] = 6; a[2][3] = 0;

			// Очікуваний результат для непарних стовпців (індекси 1 та 3):
			// maxCol1 = 10, maxCol3 = 12
			// Сума = 10 + 12 = 22
			int expectedSum = 22;

			// Виклик вашої рекурсивної функції з основного коду
			int actualSum = SumMaxInOddColumns(a, 1, k, n);

			// Перевірка відповідності
			Assert::AreEqual(expectedSum, actualSum);

			// Очищення пам'яті
			for (int i = 0; i < k; i++) {
				delete[] a[i];
			}
			delete[] a;
		}
	};
}