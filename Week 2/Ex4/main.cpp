#include <iostream>
#include <conio.h>


using namespace std;

template<typename T> 
T** AllocateArrayInFreeStore(int rows, int columns)
{
	T** freeStoreArray;

	freeStoreArray = new T*[rows];

	for (int i = 0; i < rows; ++i)
	{
		freeStoreArray[i] = new T[columns];
	}

	return freeStoreArray;
}

template<typename T>
void FreeFreeStoreArray(T** array, int rows)
{
	for (int i = 0; i < rows; ++i)
	{
		delete[] array[i];
	}

	delete[] array;
}


int main()
{
	unsigned int rows = 0;
	unsigned int columns = 0;
	unsigned int i, j;
	int value;

	cout << "Enter the number of rows: ";
	cin >> rows;

	cout << endl;

	cout << "Enter the number of columns: ";
	cin >> columns;

	int ** my2DArray = AllocateArrayInFreeStore<int>(rows, columns);

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < rows; ++j)
		{
			cout << "Enter the value for row: " << i + 1;
			cout << " and column: " << j + 1 << " :\t";
			cin >> value;

			my2DArray [i][j] = value;
		}
	}

	cout << endl;

	cout << "--------------------------------------------------" << endl;
	cout << " Your entered values are : \n";
	cout << endl;

	for (i = 0; i < rows; ++i)
	{
		for (j = 0; j < columns; ++j)
		{
			cout << my2DArray[i][j];
			cout << "\t";
		}
		cout << endl;
	}

	FreeFreeStoreArray<int>(my2DArray, rows);

	_getch();

	return 0;
}