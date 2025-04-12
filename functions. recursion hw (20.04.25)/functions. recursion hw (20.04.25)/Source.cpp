#include "Header.h"
int main()
{
	srand(time(0));
	//1
	const int size = 5;
	int ar[size];
	for (int i = 0; i < size; i++)
		ar[i] = rand() % 51;

	for (int i = 0; i < size; i++)
		cout << ar[i] << " ";

	cout << "\n";
		
	am(ar, size);
	cout << "\n";
	
	//2
	maxNmin(ar, size);

	//3
	swap(ar, size);
}