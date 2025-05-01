// Adam Nafea
// TicTacToe
// 01-04-2025

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

char board[3][3];
char currentPlayer;
int mode;

// Function declarations
void drawBoard();
void printBoard();
void resetBoard();
void playGame();
void playerMove();
void computerMove();
void switchPlayer();
int isWin(char player);
int isDraw();

int main() {
    int choice;

    do {
        printf("=== TIC TAC TOE ===\n");
        printf("1. Player vs Player\n");
        printf("2. Player vs Computer\n");
        printf("3. Exit\n");
        printf("Choose a mode: ");
        scanf_s("%d", &choice); 

        if (choice == 1 || choice == 2) {
            mode = choice;
            playGame();
        }
        else if (choice == 3) {
            printf("Goodbye!\n");
            break;
        }
        else {
            printf("Invalid choice. Try again.\n");
        }

        printf("\nPlay again? (1 = Yes, 0 = No): ");
        scanf_s("%d", &choice); 
    } while (choice == 1); 

    return 0;
}

// Clears the board
void resetBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

// Prints the current board
void printBoard() {
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n\n", board[2][0], board[2][1], board[2][2]);
}

// Checks if the given player has won
int isWin(char player) {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            return 1;
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return 1;

    return 0;
}

// Checks if the board is full (draw)
int isDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return 0;
    return 1;
}

// Human move
void playerMove() {
    int row, col;
    while (1) {
        printf("Player %c, enter your move (row and column: 1-3 1-3): ", currentPlayer);
        scanf_s("%d %d", &row, &col); 
        row--; col--;

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            break;
        }
        else {
            printf("Invalid move. Try again.\n");
        }
    }
}

// Computer makes a move randomly
void computerMove() {
    int row, col;
    srand((unsigned int)time(NULL)); // Initialize random seed 

    while (1) {
        row = rand() % 3;
        col = rand() % 3;
        if (board[row][col] == ' ') {
            board[row][col] = 'O'; // Computer always plays 'O'
            printf("Computer chose: %d %d\n", row + 1, col + 1);
            break;
        }
    }
}

// Switch players
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Main game loop
void playGame() {
    resetBoard();
    currentPlayer = 'X'; // X always starts

    while (1) {
        printBoard();

        if (mode == 1 || (mode == 2 && currentPlayer == 'X')) {
            playerMove();
        }
        else {
            computerMove();
        }

        if (isWin(currentPlayer)) {
            printBoard();
            printf("Player %c wins!\n", currentPlayer);
            break;
        }
        else if (isDraw()) {
            printBoard();
            printf("It's a draw!\n");
            break;
        }

        switchPlayer();
    }
}
