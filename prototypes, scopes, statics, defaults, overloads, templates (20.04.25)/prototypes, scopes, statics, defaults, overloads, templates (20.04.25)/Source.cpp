#include "Header.h"
int main()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	srand(time(0));
	rand();
	system("title Bomberman");

	// cursor hide
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = false;
	cursor.dwSize = 100; // 1-100
	SetConsoleCursorInfo(h, &cursor);

	const int HEIGHT = 25;
	const int WIDTH = 65;
	int map[HEIGHT][WIDTH] = {};
	// ASCII Table
	//for (int i = 0; i < 256; i++)
	//{
	//	cout << (char)i << " - " << i << "\n";
	//}

	// MODEL (логіка заповнення масиву)
	InitModel(map, HEIGHT, WIDTH);

	///////////////////////////////////////////////////////////

	// VIEW (подання - як буде виглядати ігрова локація)
	DrawModel(map, HEIGHT, WIDTH);

	////////////////////////////////////////////////////////////
	// показ ГГ
	COORD hero;
	hero.X = 0;
	hero.Y = 2;

	int coins_collected = 0;
	COORD coins_info;
	coins_info.X = WIDTH + 1;
	coins_info.Y = 0;

	SetConsoleCursorPosition(h, coins_info);
	SetConsoleTextAttribute(h, Color::DARKYELLOW);
	cout << "COINS: ";
	SetConsoleTextAttribute(h, Color::YELLOW);
	cout << coins_collected;

	while (true)
	{
		MoveHero(hero, map);
		HandlePosition(hero, map, coins_collected);
		DrawHero(hero);
	}

	Sleep(INFINITE);
}