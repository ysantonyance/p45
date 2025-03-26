#include <iostream>
using namespace std;

int main()
{

	//равнобедренный треугольник
	/*
	int n;
	cout << "set the height for the triangle: ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i >= j && i + j >= n - 1)
				cout << " * ";
			else
				cout << "   ";
		}
		cout << "\n";
	}
	cout << "\n";
	*/
	


	//ромбик
	/*
	int n;
	cout << "enter the size of rhomb(odd number like 3, 5, 7): ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		int spaces, stars;

		if (i <= n / 2) {
			spaces = (n / 2) - i;
			stars = 2 * i + 1;
		}
		else {
			spaces = i - (n / 2);
			stars = 2 * (n - i - 1) + 1;
		}

		for (int j = 0; j < spaces; j++) {
			cout << " ";
		}

		for (int j = 0; j < stars; j++) {
			cout << "*";
		}

		cout << "\n"; 
	}
	*/


	//стрелочка
	


	//восьмерка
	/*
	int n;
	cout << "enter the size: ";
	cin >> n;

	for (int i = 0; i < n; i++) 
	{
		if (i == 0 || i == n - 1) 
			cout << " ***";
		else 
			cout << "*   *";
		cout << "\n";
	}

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < 2; j++) cout << " "; 
		if (i == 0 || i == n - 1) 
			cout << " ***";
		else 
			cout << "*   *";
		cout << "\n";
	}
	*/
	
	


}