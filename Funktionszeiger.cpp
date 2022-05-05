// Funktionszeiger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void sagWas();
double wurzel(double, int);
void f1();
void f2();
void f3();
void f4();

bool ascending(int, int);
bool descending(int, int);

bool evensFirst(int, int);

void bubbleSort(int[], int);
void bSort(int[], int, bool (*)(int, int) = ascending);

void bubbleSortAsc(int[], int);
void bubbleSortDesc(int[], int);

void ausgabe(const int[], int);

int main()
{
	locale::global(locale("German_germany"));

	cout << "main: " << main << endl;
	cout << "&main: " << &main << endl;

	void (*fzSagWas)() = sagWas;

	fzSagWas();

	double (*fzWurzel)(double, int) = wurzel;

	cout << fzWurzel(27, 3) << endl;
	cout << fzWurzel(256, 4) << endl;

	// fzWurzel = sagWas; // fehler

	void (*fz[])() { f1, f2, f3, f4 };

	for (auto & f : fz)
	{
		f();
	}

	int lotto[]{ 31,45,3,19,33,9 };

	/*bubbleSort(lotto, size(lotto));

	ausgabe(lotto, size(lotto));*/

	/*bubbleSortAsc(lotto, size(lotto));

	ausgabe(lotto, size(lotto));

	bubbleSortDesc(lotto, size(lotto));

	ausgabe(lotto, size(lotto));*/

	bSort(lotto, size(lotto));

	ausgabe(lotto, size(lotto));

	bSort(lotto, size(lotto), descending);

	ausgabe(lotto, size(lotto));

	int arrNumbers[]{ 3, 7, 9, 5, 6, 1, 8, 2, 4 };

	ausgabe(arrNumbers, size(arrNumbers));

	bSort(arrNumbers, size(arrNumbers), evensFirst);

	ausgabe(arrNumbers, size(arrNumbers));

	int oddNumbers[]{ 3, 7, 9, 5, 1, 13, 21, 27 };

	ausgabe(oddNumbers, size(oddNumbers));

	bSort(oddNumbers, size(oddNumbers), evensFirst);

	ausgabe(oddNumbers, size(oddNumbers));

	return EXIT_SUCCESS;
}

void sagWas()
{
	cout << "was ?" << endl;
}

double wurzel(double basis, int exponent)
{
	if (basis >= 0)
		return pow(basis, 1.0 / exponent);

	return -1.0;
}

void f1()
{
	cout << "C++ ";
}
void f2()
{
	cout << "ist ";

}
void f3()
{
	cout << "toll ";

}
void f4() 
{
	cout << endl;

}

bool ascending(int x, int y)
{
	return x > y;
}

bool descending(int x, int y)
{
	return x < y;
}

bool evensFirst(int x, int y)
{
	if (x % 2 == 0 && y % 2 == 1)
		return false;

	if (x % 2 == 1 && y % 2 == 0)
		return true;

	return ascending(x, y);
}

void bubbleSort(int arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] > arr[j])
			{
				swap(arr[i], arr[j]);
			}
		}
	}
}

void bSort(int arr[], int size, bool (*comFunc)(int, int))
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (comFunc(arr[i],arr[j]))
			{
				swap(arr[i], arr[j]);
			}
		}
	}
}

void bubbleSortAsc(int arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (ascending(arr[i], arr[j]))
			{
				swap(arr[i], arr[j]);
			}
		}
	}
}

void bubbleSortDesc(int arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (descending(arr[i], arr[j]))
			{
				swap(arr[i], arr[j]);
			}
		}
	}
}

void ausgabe(const int arr[], int size)
{
	for (int i = 0; i < size ; i++)
	{
		cout << arr[i] << ", ";
	}

	cout << endl;
}
