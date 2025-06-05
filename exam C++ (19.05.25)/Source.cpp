#include "Header.h"

int main()
{
	int rows = 3;
	int cols = rows;
	char** board;
	Player player1, player2;
	int choice;
	initPlayers(&player1, &player2);
	explaining();

	createBoard(&board, rows, cols);
	fillBoard(board, rows, cols);

	gameloop(board, rows, cols, player1, player2);

	deleteBoard(board, rows);
}