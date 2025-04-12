#include <iostream>
using namespace std;

void output(int ar[], const int size)
{
	for (int i = 0; i < size; i++)
		cout << ar[i] << " ";
	cout << "\n";
}

void am(int ar[], const int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += ar[i];
	cout << (double)sum / size;
}

void maxNmin(int ar[], const int size)
{
	int min = ar[0];
	int max = ar[size];
	for (int i = 0; i < 5; i++)
		if (ar[i] < ar[i - 1])
			min = ar[i];
		else
			max = ar[i];
	cout << "min: " << min << "\n";
	cout << "max: " << max << "\n";
}

void swap(int ar[], const int size)
{
	for (int i = 0; i < size / 2; i++)
	{
		int j = size - 1 - i;
		int temp = ar[i];
		ar[i] = ar[j];
		ar[j] = temp;
		j--;
	}
	output(ar, size);
}