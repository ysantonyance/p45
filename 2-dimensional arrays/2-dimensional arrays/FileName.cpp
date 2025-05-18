#include <iostream>
#include <windows.h> // COORD HANDLE SetConsoleTextAttribute SetConsoleCursorPosition
#include <conio.h> // _getch
using namespace std;


enum GameObject : short { HALL, WALL, COIN, ENEMY, LIFEPACK };
enum Color : short {
    BLACK, DARKBLUE, DARKGREEN, TURQUOISE, DARKRED,
    PURPLE, DARKYELLOW, GREY, DARKGREY, BLUE, GREEN,
    CYAN, RED, PINK, YELLOW, WHITE
};
enum Key : short {
    LEFT = 75, RIGHT = 77, UP = 72, DOWN = 80,
    ENTER = 13, SPACE = 32, ESCAPE = 27, BACKSPACE = 8
};


int main() {

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    srand(time(0));
    rand();
    system("title Bomberman");

    const int HEIGHT = 25;
    const int WIDTH = 65;
    int map[HEIGHT][WIDTH] = {};
    int coinsCollected = 0;
    int totalCoins = 0;
    int health = 100;
    // ASCII Table
    //for (int i = 0; i < 256; i++)
    //{
    // cout << (char)i << " - " << i << "\n";
    //}

    // MODEL (логіка заповнення масиву)
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            map[y][x] = rand() % 5; // 0 1 2 3 4

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
                int r = rand() % 10; // 0 1 2 3 4 5 6 7 8 9
                if (r != 0) {
                    map[y][x] = GameObject::HALL;
                }
            }

            if (map[y][x] == GameObject::COIN)
                totalCoins++;
        }
    }

    ///////////////////////////////////////////////////////////

    // VIEW (подання - як буде виглядати ігрова локація)
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            switch (map[y][x]) {
            case GameObject::HALL: // 0
                // як показати коридор
                SetConsoleTextAttribute(h, Color::BLACK);
                cout << " ";
                break;
            case GameObject::WALL: // 1
                SetConsoleTextAttribute(h, Color::DARKGREEN);
                // cout << "#";
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
            case GameObject::LIFEPACK:
                SetConsoleTextAttribute(h, Color::CYAN);
                cout << "+";
                break;
                // case GameObject::SMTH_ELSE:
                 // як показати щось інше
                // break;
            }
        }
        cout << "\n";
    }

    ////////////////////////////////////////////////////////////
    // показ ГГ
    COORD hero;
    hero.X = 0;
    hero.Y = 2;
    SetConsoleCursorPosition(h, hero);
    SetConsoleTextAttribute(h, Color::BLUE);
    cout << "O";

    // ігровий двигунчик
    while (true) {
        int code = _getch(); // get character
        if (code == 224) {
            code = _getch();
        }

        // стирання ГГ в "старих" координатах
        SetConsoleCursorPosition(h, hero);
        SetConsoleTextAttribute(h, Color::BLACK);
        cout << " ";


        // cout << code << "\n";
        switch (code) {
        case Key::LEFT:
            if (hero.X > 0 && map[hero.Y][hero.X - 1] != GameObject::WALL)
                hero.X--;
            break;
        case Key::RIGHT:
            if (map[hero.Y][hero.X + 1] != GameObject::WALL)
                hero.X++;
            break;
        case Key::UP:
            if (map[hero.Y - 1][hero.X] != GameObject::WALL)
                hero.Y--;
            break;
        case Key::DOWN:
            if (map[hero.Y + 1][hero.X] != GameObject::WALL)
                hero.Y++;
            break;
        }

        if (map[hero.Y][hero.X] == COIN) {
            coinsCollected++;
            map[hero.Y][hero.X] = HALL;
        }
        else if (map[hero.Y][hero.X] == ENEMY) {
            health -= 25;
            map[hero.Y][hero.X] = HALL;
        }
        else if (map[hero.Y][hero.X] == LIFEPACK) {
            if (health < 100) {
                health += 25;
                if (health > 100) health = 100;
                map[hero.Y][hero.X] = HALL;
            }
        }



        COORD statPos;
        statPos.X = WIDTH + 2;
        statPos.Y = 0;
        SetConsoleCursorPosition(h, statPos);
        SetConsoleTextAttribute(h, WHITE);
        cout << "HP: " << health << "  Coins: " << coinsCollected << "/" << totalCoins << "   ";

        // перемога: вихід
        if (hero.X == WIDTH - 1 && hero.Y == HEIGHT - 3) {
            SetConsoleCursorPosition(h, { 0, HEIGHT + 1 });
            SetConsoleTextAttribute(h, GREEN);
            cout << "Victory - you found a way out\n";
            break;
        }

        // перемога: монетки
        if (coinsCollected == totalCoins) {
            SetConsoleCursorPosition(h, { 0, HEIGHT + 1 });
            SetConsoleTextAttribute(h, YELLOW);
            cout << "Victory - you collected all the coins\n";
            break;
        }

        // поразка: 0 HP
        if (health <= 0) {
            SetConsoleCursorPosition(h, { 0, HEIGHT + 1 });
            SetConsoleTextAttribute(h, RED);
            cout << "Game over - you died\n";
            break;
        }

        // показ героя
        SetConsoleCursorPosition(h, hero);
        SetConsoleTextAttribute(h, BLUE);
        cout << "O";
    }

    Sleep(INFINITE);
}