#include <iostream>
#include <windows.h>
using namespace std;

enum Color
{
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Purple = 5,
	Yellow = 6,
	White = 7
};

void Line(int size, char symb, Color color, bool direction)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, color);

	if (direction == true)
	{
		for (int i = 0; i < size; i++)
		{

			cout << symb;
		}
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			cout << symb << "\n";
		}
	}
	SetConsoleTextAttribute(h, Color::White);
}

void Rectangle(int width, int height, char symb_out, char symb_in, Color out_color,
	Color in_color, int X, int Y)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD position;
	
	for (int i = 0; i <= height; i++)
	{
		position.X = X;
		position.Y = Y + i;
		SetConsoleCursorPosition(h, position);

		for (int j = 0; j <= width; j++)
		{

			if (i == 0 || i == height || j == 0 || j == width) 
			{
				SetConsoleTextAttribute(h, out_color);
				cout << symb_out;
			}
			else
			{
				SetConsoleTextAttribute(h, in_color);
				cout << symb_in;
			}
		}
		cout << "\n";
	}
	SetConsoleTextAttribute(h, Color::White);
}

double Cube(double x)
{
	return x * x * x;
}

bool Prime(int x)
{
	for (int i = 2; i < x; i++)
	{
		if (x % i == 0)
			return false;
		else
			return true;
	}
}

int main()
{

	//1
	//Line(20, '@', Red, true);

	//2
	//Rectangle(5, 6, '#', '*', Red, Blue, 5, 1);

	//3
	//cout << Cube(3);

	//4
	cout << boolalpha;
	cout << Prime(11);

}