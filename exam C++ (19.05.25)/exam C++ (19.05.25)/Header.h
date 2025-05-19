#include <iostream>
#include <windows.h>
using namespace std;

struct Player
{
	string name;
	char symbol;
};

void createBoard(char*** board, int rows, int cols);
void fillBoard(char** board, int rows, int cols);
void deleteBoard(char** board, int rows);
void printBoard(char** board, int rows, int cols);
void explaining();
bool makeMove(char** board, int rows, int cols, Player* player, int choice);
bool checkWin(char** board);
bool checkDraw(char** board, int rows, int cols);
void saveResult(const Player* winner);
void initPlayers(Player* p1, Player* p2);
void gameloop(char** board, int rows, int cols, Player player1, Player player2);

//инициализируем карту
void createBoard(char*** board, int rows, int cols)
{
	*board = new char*[rows];
	for (int i = 0; i < rows; i++)
	{
		(*board)[i] = new char[cols];
	}
}

//заполняем ее
void fillBoard(char** board, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			board[i][j] = '-';
		}
	}
}

//удаляем чтобы не было утечки памяти
void deleteBoard(char** board, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] board[i];
	}
	delete[] board;
}

//вывод текста в консоль
void printBoard(char** board, int rows, int cols)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			//перекрашиваю символы в оригинальные цвета символов игры крестики нолики
			if (board[i][j] == 'X') SetConsoleTextAttribute(h, 9);
			else if (board[i][j] == 'O') SetConsoleTextAttribute(h, 12);
			else SetConsoleTextAttribute(h, 15);
			
			cout << board[i][j];
			SetConsoleTextAttribute(h, 15);
			if (j < cols - 1) cout << " | ";
		}
		cout << "\n";
	}
}

//объяснение работу схемы
void explaining()
{
	cout << "please follow this scheme\n";
	cout << "1 | 2 | 3\n4 | 5 | 6\n7 | 8 | 9\n\n";
}

//для того чтобы заменять '-' на символ
bool makeMove(char** board, int rows, int cols, Player* player, int choice)
{
	int row = (choice - 1) / cols; //переобразования выбора в позицию на карте
	int col = (choice - 1) % cols; //тут так же

	//если выбор равен числу НЕ из нашего диапазона или клетка уже заполнена символом, то выводится информация о том что выбор невалиден
	if (choice < 1 || choice > 9 || board[row][col] != '-') {
		cout << "Invalid move. Try again.\n";
		return false;
	}

	board[row][col] = player->symbol;
	return true;
}

//проверка победа
//если к примеру 1 2 3 равны друг другу и не равны '-', то засчитывается победа
bool checkWin(char** board)
{
	//по горизонатли
	if (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] != '-') return true;
	if (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] != '-') return true;
	if (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] != '-') return true;

	//по вертикали
	if (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] != '-') return true;
	if (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] != '-') return true;
	if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] != '-') return true;

	//по диагонали
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '-') return true;
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-') return true;
		
	return false;
}

//проверка на ничью
bool checkDraw(char** board, int rows, int cols)
{
	if (checkWin(board)) return false;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (board[i][j] == '-') return false; // осталось свободное место на карте значит значит не ничья
		}
	}

	return true; // нет победителя и карта заполнена значит ничья
}

//результат игры создает и записывает результат в файле
void saveResult(const Player* winner)
{
	FILE* file;
	int error_code = fopen_s(&file, "C:/Users/zinov/OneDrive/Desktop/tic-tac-toe results.txt", "w");
	if (error_code == 0 && file != nullptr) {
		if (winner != nullptr)
		{
			fputs("The winner is ", file);
			fputs(winner->name.c_str(), file);
			fputs("\n", file);
		}
		else fputs("it's a draw\n", file);
		fclose(file);
	}
	else {
		cout << "Error code: " << error_code << "\n";
	}
}

//инициализация игроков
void initPlayers(Player* p1, Player* p2)
{
	//игроки вводят имя и символ с которым будут играть
	cout << "enter name and symbol(X or O) for the 1st player: \n";
	cin >> p1->name >> p1->symbol;
	cout << "\n";

	cout << "enter name and symbol(X or O) for the 2nd player: \n";
	cin >> p2->name >> p2->symbol;
}

//цикл с помощью которого игра не останавливается после 1 хода
void gameloop(char** board, int rows, int cols, Player player1, Player player2)
{
	bool gameover = false; //инструмент для того чтобы контролировать цикл
	Player* currentPlayer = &player1;

	while (!gameover)
	{
		printBoard(board, rows, cols);

		int choice;
		cout << currentPlayer->name << ", enter your move: ";
		cin >> choice;

		//если ход сделан неправильно, то есть игрок попробовал сходить на место которое уже заполнено символом или ввел число которого нет в диапазоне
		//то ему выводится сообщение о том что его ход неккоректен и просьба сделать корректный ход до того момента пока он не введет подходящий ход
		while (!makeMove(board, rows, cols, currentPlayer, choice)) 
		{
			cout << currentPlayer->name << ", enter your move again: ";
			cin >> choice;
		}

		if (checkWin(board))
		{
			//если есть победитель, то его имя выводится в консоли и записывается в файл
			printBoard(board, rows, cols);
			cout << currentPlayer->name << " wins!\n";
			saveResult(currentPlayer);
			gameover = true;
		}
		else if (checkDraw(board, rows, cols))
		{
			//если ничья, то об этом выводится информация и так же записывается в файл
			printBoard(board, rows, cols);
			cout << "it's a draw!\n";
			saveResult(nullptr);
			gameover = true;
		}
		else currentPlayer = (currentPlayer == &player1) ? &player2 : &player1;
		//если ход первого игрока закончен, то ходит другой и наоборот
	}
}