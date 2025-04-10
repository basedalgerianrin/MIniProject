//Adam Nafea
//TicTacToe
//01-04-2025

#define _USE_MATH_DEFINES 
#include<stdio.h>
#include<math.h>

void drawBoard();
bool checkWinner();
bool checkDraw();
char board[3][3];
char current_marker;
int placeMarker(int);


int main()
{

	char player1 = 'X';
	char player2 = 'O';

	drawBoard();
	placeMarker();
	checkWinner();
	checkDraw();


	return 0;
}

void drawBoard()
{
	char board[3][3];
	printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
	printf("---|---|---\n");
	printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
	printf("---|---|---\n");
	printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = ' ';
		}
	}
}


int placeMarker(int slot) {
	int row = slot / 3;
	int col = slot % 3;

	if (board[row][col] != ' ') {
		return 0;
	}
	board[row][col] = current_marker;
	return 1;
}
bool checkWinner() {


	return 0;
}
bool checkDraw() {


	return 0;
}