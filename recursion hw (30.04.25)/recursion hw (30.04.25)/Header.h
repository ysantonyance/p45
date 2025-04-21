#include <iostream>
using namespace std;

void onedigit(int num, int start = 1)
{
	cout << start << " ";
	if (start < num)
		onedigit(num, start + 1);
	else
		return;
}

void twodigits(int A, int B)
{
	cout << A << " ";
	if (A < B)
		twodigits(A + 1, B);
	else if (A > B)
		twodigits(A - 1, B);
}

int degree(int num, int extent)
{
	if (extent == 0)
		return 0;
	else
		return num * degree(num, extent - 1);
}

int SumInRange(int start, int end, int sum = 0)
{
	if (start > end)
		return 0;
	else if (start == end)
		return start;
	else
		return start += SumInRange(start + 1, end);

}

int fibonacci(int num)
{
	if (num == 0)
		return 1;
	else if (num == 1)
		return 1;
	else
		return fibonacci(num - 1) + fibonacci(num - 2);
}

int DigSum(int num)
{
	if (num > 0 && num < 10)
		return num;
	else if (num > 9 && num < 100)
		return DigSum(num / 10) + DigSum(num % 10);
	else if (num > 99 && num < 1000)
		return DigSum(num / 100) + DigSum(num / 10 % 10) + DigSum(num % 10);
	else if (num > 999 && num < 10000)
		return DigSum(num / 1000) + DigSum(num / 100 % 10) + DigSum(num / 10 % 10) + DigSum(num % 10);
	else
		return 0;
}
