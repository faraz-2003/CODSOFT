#include <iostream>
using namespace std;

const int BOARD_SIZE = 3;
char board[BOARD_SIZE][BOARD_SIZE] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char currentPlayer = 'X';

// Function to display the game board
void displayBoard() {
    cout << "\n";
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            cout << " " << board[i][j];
            if (j < BOARD_SIZE - 1) cout << " |";
        }
        cout << "\n";
        if (i < BOARD_SIZE - 1) cout << "---|---|---\n";
    }
    cout << "\n";
}

// Function to check if the current player has won
bool checkWin() {
    // Check rows and columns
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;
    
    return false;
}

// Function to check if the game is a draw
bool checkDraw() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') return false;
        }
    }
    return true;
}

// Function to update the board with the player's move
bool updateBoard(int move) {
    int row = (move - 1) / BOARD_SIZE;
    int col = (move - 1) % BOARD_SIZE;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentPlayer;
        return true;
    } else {
        cout << "Invalid move! Try again.\n";
        return false;
    }
}

// Function to switch players
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int main() {
    bool gameWon = false;
    bool gameDraw = false;
    int move;

    cout << "Welcome to Tic-Tac-Toe!\n";
    displayBoard();

    while (!gameWon && !gameDraw) {
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;

        if (move < 1 || move > 9) {
            cout << "Invalid input! Please enter a number between 1 and 9.\n";
            continue;
        }

        if (updateBoard(move)) {
            displayBoard();
            gameWon = checkWin();
            gameDraw = checkDraw();

            if (!gameWon && !gameDraw) {
                switchPlayer();
            }
        }
    }

    if (gameWon) {
        cout << "Congratulations! Player " << currentPlayer << " wins!\n";
    } else if (gameDraw) {
        cout << "It's a draw!\n";
    }

    // Ask if players want to play again
    char playAgain;
    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;

    if (playAgain == 'y' || playAgain == 'Y') {
        // Reset the board and start the game again
        board[0][0] = '1'; board[0][1] = '2'; board[0][2] = '3';
        board[1][0] = '4'; board[1][1] = '5'; board[1][2] = '6';
        board[2][0] = '7'; board[2][1] = '8'; board[2][2] = '9';
        currentPlayer = 'X';
        main();
    }

    return 0;
}
