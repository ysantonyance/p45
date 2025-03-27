#include <iostream>
using namespace std;

int main()
{

	//1
	//Y + rand() % (X - Y + 1)
	/*
	srand(time(0));
	int ar[10], sum = 0;
	for (int i = 0; i < 10; i++)
	{
		ar[i] = (-20) + rand() % (20 - (-20) + 1);
	}
	for (int i = 0; i <= 9; i++)
	{
		cout << ar[i] << " ";
	}
	cout << "\n";

	for (int i = 0; i <= 9; i++)
	{
		sum += ar[i];
	}

	cout << "sum = " << sum << "\n";
	cout << "arithmetic mean: " << (double)sum / 10 << "\n";
	*/
	

	//2
	/*
	srand(time(0));
	int ar[100], num, amount = 0;
	for (int i = 0; i < 100; i++)
	{
		ar[i] = rand() % 101;
	}
	for (int i = 0; i <= 99; i++)
	{
		cout << ar[i] << " ";
	}
	cout << "\n";

	cout << "enter your num: ";
	cin >> num;

	for (int i = 0; i <= 99; i++)
	{
		if (ar[i] == num)
			amount++;
	}

	cout << "in this list your number has repeated " << amount << " times\n";
	*/


	//3
	/*
	srand(time(0));
	int ar[20];
	for (int i = 0; i < 20; i++)
	{
		ar[i] = rand() % 101;
	}
	for (int i = 0; i < 20; i++)
	{
		cout << ar[i] << " ";
	}
	cout << "\n";

	int max = ar[0], maxIndex = 0;
	int min = ar[0], minIndex = 0;

	for (int i = 0; i < 20; i++)
	{
		if (ar[i] > max)
		{
			max = ar[i];
			maxIndex = i;
		}
			
		if (ar[i] < min)
		{
			min = ar[i];
			minIndex = i;
		}
	}

	cout << "max: " << max << ", number: " << maxIndex + 1 << "\n";
	cout << "min: " << min << ", number: " << minIndex + 1 << "\n";
	*/


	//4
	/*
	srand(time(0));
	int ar[200], digit1 = 0, digit2 = 0, digit3 = 0;
	for (int i = 0; i < 200; i++)
	{
		ar[i] = rand() % 201;
	}
	for (int i = 0; i < 200; i++)
	{
		cout << ar[i] << " ";
	}
	cout << "\n\n";

	for (int i = 0; i < 200; i++)
	{
		if (ar[i] / 10 == 0)
			digit1++;
		else if (ar[i] / 10 > 0 && ar[i] / 10 < 10)
			digit2++;
		else //if (ar[i] / 10 >= 10 && ar[i] / 10 < 100)
			digit3++;
	}

	cout << (double)digit1 / 200 * 100 << "% of numbers with 1 digit\n";
	cout << (double)digit2 / 200 * 100 << "% of numbers with 2 digits\n";
	cout << (double)digit3 / 200 * 100 << "% of numbers with 3 digits\n";
	*/
	

	//5
	/*
	srand(time(0));
	int m, n;
	const int size = 100;
	cout << "enter the size of the 1st array(m) and the second one(n)\nboth should be not greater than " << size << "\n";
	cin >> m >> n;

	int ar1[size], ar2[size];
	for (int i = 0; i < m; i++)
	{
		ar1[i] = rand() % 11;
	}
	for (int i = 0; i < n; i++)
	{
		ar2[i] = rand() % 11;
	}

	cout << "array 1: ";
	for (int i = 0; i < m; i++)
	{
		cout << ar1[i] << " ";
	}
	cout << "\n";
	cout << "array 2: ";
	for (int i = 0; i < n; i++)
	{
		cout << ar2[i] << " ";
	}
	cout << "\n";

	int ar3[size], j = 0;;
	for (int i = 0; i < m; i++)
	{
		ar3[i] = ar1[i];
	}
	for (int i = m; i < n+m; i++)
	{
		ar3[i] = ar2[j];
		j++;
	}

	cout << "array 3: ";
	for (int i = 0; i < m + n; i++)
	{
		cout << ar3[i] << " ";
	}
	cout << "\n";
	*/


	//6
	//Y + rand() % (X - Y + 1)
	/*
	srand(time(0));
	int ar1[5], ar2[5];
	for (int i = 0; i < 5; i++)
	{
		ar1[i] = 1 + rand() % (42 - 1 + 1);
	}
	
	//for (int i = 0; i < 5; i++)
	//{
	//	cout << ar1[i] << " ";
	//}
	//cout << "\n";
	
	

	cout << "enter your 5 numbers(from 1 to 42)\n";
	for (int i = 0; i < 5; i++)
	{
		cin >> ar2[i];
	}
	
	int similar = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (ar1[i] == ar2[j])
				similar++;
		}
	}

	switch (similar)
	{
	case 3:
		cout << "you guessed 3 numbers right!\nyou get 100 credits :)\n";
		break;
	case 4:
		cout << "you guessed 4 numbers right!\nyou get 500 credits :)\n";
		break;
	case 5:
		cout << "you guessed all the numbers right!\nyou get 2500 credits :)\n";
		break;
	default:
		cout << "sorry, you didn't guess enough numbers right to receive any credits :(\n";
		break;
	}
	*/
	
}