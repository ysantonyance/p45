#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Header.h"  // Подключаем заголовочный файл с прототипами функций

using namespace std;

void InitModel(int map[][65], int HEIGHT, int WIDTH)
{
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            map[y][x] = rand() % 4; // 0 1 2 3

            // рамка по краях
            if (x == 0 || y == 0 || x == WIDTH - 1 || y == HEIGHT - 1)
                map[y][x] = GameObject::WALL;

            // отвори для входу і виходу
            if (x == 0 && y == 2 ||
                x == 1 && y == 2 ||
                x == 2 && y == 2 ||
                x == WIDTH - 1 && y == HEIGHT - 3 ||
                x == WIDTH - 2 && y == HEIGHT - 3 ||
                x == WIDTH - 3 && y == HEIGHT - 3)
                map[y][x] = GameObject::HALL;

            if (map[y][x] == GameObject::ENEMY) {
                int r = rand() % 10;
                if (r != 0) {
                    map[y][x] = GameObject::HALL;
                }
            }
        }
    }
}

void DrawModel(const int map[][65], int HEIGHT, int WIDTH)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            switch (map[y][x]) {
            case GameObject::HALL: // 0
                SetConsoleTextAttribute(h, Color::BLACK);
                cout << " ";
                break;
            case GameObject::WALL: // 1
                SetConsoleTextAttribute(h, Color::DARKGREEN);
                cout << (char)178;
                break;
            case GameObject::COIN:
                SetConsoleTextAttribute(h, Color::YELLOW);
                cout << ".";
                break;
            case GameObject::ENEMY:
                SetConsoleTextAttribute(h, Color::RED);
                cout << "O";
                break;
            }
        }
        cout << "\n";
    }
}

void DrawHero(COORD hero)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(h, hero);
    SetConsoleTextAttribute(h, Color::BLUE);
    cout << "O";
}

void MoveHero(COORD& hero, const int map[][65])
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    while (true) {
        int code = _getch();
        if (code == 224) {
            code = _getch();
        }

        COORD old_position = hero;
        bool has_been_moved = false;

        switch (code) {
        case Key::LEFT:
            if (hero.X > 0 && map[hero.Y][hero.X - 1] != GameObject::WALL) {
                has_been_moved = true;
                hero.X--;
            }
            break;
        case Key::RIGHT:
            if (map[hero.Y][hero.X + 1] != GameObject::WALL) {
                has_been_moved = true;
                hero.X++;
            }
            break;
        case Key::UP:
            if (map[hero.Y - 1][hero.X] != GameObject::WALL) {
                has_been_moved = true;
                hero.Y--;
            }
            break;
        case Key::DOWN:
            if (map[hero.Y + 1][hero.X] != GameObject::WALL) {
                has_been_moved = true;
                hero.Y++;
            }
            break;
        }

        if (has_been_moved) {
            SetConsoleCursorPosition(h, old_position);
            SetConsoleTextAttribute(h, Color::BLACK);
            cout << " ";
            SetConsoleCursorPosition(h, hero);
            SetConsoleTextAttribute(h, Color::BLUE);
            cout << "O";
        }
    }
}

void HandlePosition(COORD hero, int map[][65], int& coins_collected)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    if (map[hero.Y][hero.X] == GameObject::COIN) {
        coins_collected++;
        map[hero.Y][hero.X] = GameObject::HALL;

        COORD coins_info;
        coins_info.X = 65 + 1;
        coins_info.Y = 0;
        SetConsoleCursorPosition(h, coins_info);

        SetConsoleTextAttribute(h, Color::DARKYELLOW);
        cout << "COINS: ";
        SetConsoleTextAttribute(h, Color::YELLOW);
        cout << coins_collected;
    }

    if (map[hero.Y][hero.X] == GameObject::ENEMY) {
        cout << "ENEMY";
    }
}
