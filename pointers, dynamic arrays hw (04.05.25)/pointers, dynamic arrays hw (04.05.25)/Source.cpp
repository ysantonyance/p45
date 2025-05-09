#include <iostream>
#include <windows.h>
using namespace std;

int main() {
	srand(time(0));

	int size;
	cout << "Please, enter size of array (5-100000): ";
	cin >> size;
	if (size <= 0) size = 5;
	if (size > 100000) size = 100000;
	int* ar = new int[size];

	for (int i = 0; i < size; i++)
	{
	ar[i] = rand() % 100; 
	cout << ar[i] << ", ";
	}
	cout << "\n";


	//ADDING AN ELEMENT
	/*
	int value;
	cout << "Please, input number to add into array: ";
	cin >> value;

	int* temp = new int[size + 1];
	for (int i = 0; i < size; i++)
	{
	temp[i] = ar[i];
	}
	temp[size] = value;
	delete[] ar;
	ar = temp;
	size++;

	for (int i = 0; i < size; i++)
	{
	cout << ar[i] << ", ";
	}
	cout << "\n";
	*/
	
	/////////////////////////////////////////////////////

	//DELETING AN ELEMENT
	/*
	int* temp = new int[size - 1];
	for (int i = 0; i < size-1; i++)
	{
		temp[i] = ar[i];
	}
	delete[] ar;
	ar = temp;
	size--;

	for (int i = 0; i < size; i++)
	{
		cout << ar[i] << ", ";
	}
	cout << "\n";
	*/
	
}