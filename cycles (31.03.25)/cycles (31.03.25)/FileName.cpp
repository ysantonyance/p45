#include <iostream>
using namespace std;

int main()
{

	//1
	/*
	int i = 0;
	int sum = 0;
	while (i != 10)
	{
		i++;
		sum += i;
	}
	cout << sum << "\n";
	*/
	
	//2
	/*
	int start, end;
	char choice;
	cout << "haii, please tell me what do you prefer in temperature C or F: ";
	cin >> choice;
	cout << "tell me the range, the start and the end: \n";
	cin >> start >> end;

	for (int i = start; i <= end; i++)
	{
		if (choice == 'C')
		{
			double F = ((double)i * 1.8 + 32);
			cout << i << "C\t" << F << "F\n";
		}
		else if (choice == 'F')
		{
			double C = ((double)i - 32) * ((double)5 / 9);
			cout << i << "F\t" << C << "C\n";
		}
		else
		{
			cout << "there's no such option in a list\n";
		}
	}
	*/
	
	//3
	/*
	srand(time(0));
	int negative = 0;
	int positive = 0;
	int zero = 0;
	int odd = 0;
	int even = 0;
	

	for (int i = 0; i < 100; i++)
	{
		int num = -100 + rand() % (100 - (-100) + 1);
		cout << num << " ";

		if (num % 2 == 0)
			even++;
		else
			odd++;

		if (num < 0)
			negative++;
		else if (num == 0)
			zero++;
		else
			positive++;
	}
	cout << "\n";
	
	cout << "in this line of numbers here's \n";
	cout << ((double)positive / 100 * 100) << "% of positive numbers\n";
	cout << ((double)negative / 100 * 100) << "% of negative numbers\n";
	cout << ((double)zero / 100 * 100) << "% of zeros\n";
	cout << ((double)even / 100 * 100) << "% of even numbers\n";
	cout << ((double)odd / 100 * 100) << "% of odd numbers\n";
	*/
	//Y + rand() % (X - Y + 1)
	

	//4
	/*
	int num;
	cout << "enter number: ";
	cin >> num;
	int res = 1;

	for (int i = 1; i <= num; i++)
	{
		res *= i;
	}

	cout << res;
	*/

	//5
	/*
	int num;
	cout << "please, enter any int number: ";
	cin >> num;
	*/
	

	
	

	//6
	/*
	int num;
	cout << "enter number: ";
	cin >> num;

	for (int i = 1; i <= 100000; i++)
	{
		if (num % i == 0)
		{
			cout << i << " ";
		}
	}
	*/

	//7
	/*
	int num;
	bool prime = true;
	cout << "enter number: ";
	cin >> num;


	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)
		{
			prime = false;
		} 
	}

	if (prime == 1)
		cout << "your number is a prime number\n";
	else
		cout << "your number is NOT a prime number\n";
	*/

	//8

	//9
	/*
	int num;
	cout << "enter number: ";
	cin >> num;

	int digit1 = num / 1000000;
	int digit2 = num / 100000 % 10;
	int digit3 = num / 10000 % 10;
	int digit4 = num / 1000 % 10;
	int digit5 = num / 100 % 10;
	int digit6 = num / 10 % 10;
	int digit7 = num % 10;

	if (digit1 == digit7 && digit2 == digit6 && digit3 == digit5)
		cout << "your num is palindrom\n";
	else
		cout << "your num is NOT palindrom\n";
	*/
	

	//10
	//srand(time(0));
	/*
	int num;
	cout << "enter number(0-1000): ";
	cin >> num;

	bool guess = false;

	while (guess != true)
	{
		int random = rand() % 1001;
		cout << random << "\n";
		int choice;
		cout << "is this number greater(1) or less(2) than yours or is it equals to yours(3)?";
		cin >> choice;

		if (choice == 3 && random == num)
		{
			cout << "yaaay, I guessed your number right :)\n";
			guess = true;
		}
		else if (choice == 2)
		{
			random = rand() % random;
			guess = false;
		}
		else if (choice == 1)
		{
			//Y + rand() % (X - Y + 1)
			random = random + rand() % (1000 - random + 1);
			guess = false;
		}
		else
		{
			cout << "there's no such an option on a list\n";
		}
	}
	*/
	


	//11
	/*
	double N, M, sum = 0;
	cout << "enter your monthly stipend(N) and start up costs(M): ";
	cin >> N >> M;

	for (int i = 1; i <= 10; i++)
	{
		sum += M;
		M = M + M * 0.05; // 4000 + 4000 * 0.05
	}

	cout << sum - (N * 10) << " UAH we should ask our parents for\n";
	*/
}