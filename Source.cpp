// Lab_7_2_2.cpp
// < Заяць, Анастасія>
// Лабораторна робота № 7.2.2
// Опрацювання багатовимірних масивів рекурсивними способами.
// Варіант 8
#include <iostream> 
#include <iomanip> 
#include <time.h> 
using namespace std;
void Create(int** a, const int rowCount, const int colCount, const int Low,
	const int High, int i, int j);
void Print(int** a, const int rowCount, const int colCount, int i, int j);
void MinMaxRows(int** a, const int rowCount, const int colCount, int rowNo, int& max);
void MaxRow(int** a, const int rowNo, const int colCount, int colNo, int& min);
int main()
{
	srand((unsigned)time(NULL));
	int Low = 7;
	int High = 65;
	int rowCount, colCount;
	cout << "n = "; cin >> colCount;
	cout << "k = "; cin >> rowCount;
	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	Create(a, rowCount, colCount, Low, High, 0, 0);
	Print(a, rowCount, colCount, 0, 0);
	int max;
	MinMaxRows(a, rowCount, colCount, 0, max);
	cout << "Min of max = " << max;
	return 0;
}
void Create(int** a, const int rowCount, const int colCount, const int Low,
	const int High, int i, int j)
{
	if (i < rowCount) {
		if (j < colCount) {
			a[i][j] = Low + rand() % (High - Low + 1);
			Create(a, rowCount, colCount, Low, High, i, j + 1);
		}
		Create(a, rowCount, colCount, Low, High, i + 1, j);
	}
}
void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
	cout << setw(4) << a[i][j];
	if (j < colCount - 1)
		Print(a, rowCount, colCount, i, j + 1);
	else
		if (i < rowCount - 1)
		{
			cout << endl;
			Print(a, rowCount, colCount, i + 1, 0);
		}
		else
			cout << endl << endl;
}
void MinMaxRows(int** a, const int rowCount, const int colCount, int rowNo, int& min)
{
	int max = a[rowNo][0];
	MaxRow(a, rowNo, colCount, 1, max);
	if (rowNo == 0)
		min = max;
	if (min > max)
		min = max;
	if (rowNo < rowCount - 1)
		MinMaxRows(a, rowCount, colCount, rowNo + 2, min);
}
void MaxRow(int** a, const int rowNo, const int colCount, int colNo, int& max)
{
	if (a[rowNo][colNo] > max)
		max = a[rowNo][colNo];
	if (colNo < colCount - 1)
		MaxRow(a, rowNo, colCount, colNo + 1, max);
}
