#include <iostream>
#include <limits>

using namespace std;

char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char currentPlayer = 'X';
int movePosition;

void displayBoard() {
    cout << "\n";
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << "\n";
    cout << "-----------\n";
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << "\n";
    cout << "-----------\n";
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << "\n";
}

void getPlayerMove() {
    while (true) {
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> movePosition;

        // Check for valid move
        if (movePosition < 1 || movePosition > 9) {
            cout << "Invalid move! Position out of range.\n";
        } else if (board[movePosition - 1] == 'X' || board[movePosition - 1] == 'O') {
            cout << "That spot is already taken. Try another one.\n";
        } else {
            board[movePosition - 1] = currentPlayer;
            break;
        }
    }
}

bool checkWin() {
    return (board[0] == board[1] && board[1] == board[2]) ||
           (board[3] == board[4] && board[4] == board[5]) ||
           (board[6] == board[7] && board[7] == board[8]) ||
           (board[0] == board[3] && board[3] == board[6]) ||
           (board[1] == board[4] && board[4] == board[7]) ||
           (board[2] == board[5] && board[5] == board[8]) ||
           (board[0] == board[4] && board[4] == board[8]) ||
           (board[2] == board[4] && board[4] == board[6]);
}

bool checkDraw() {
    for (int i = 0; i < 9; i++) {
        if (board[i] != 'X' && board[i] != '0') return false;
    }
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? '0' : 'X';
}

int main() {
    cout << "-----------------------------------\n";
    cout << "Welcome to Tic-Tac-Toe, by Nitya!\n";
    cout << "Player 1: X | Player 2: 0\n";
    cout << "-----------------------------------\n";

    while (true) {
        displayBoard();
        getPlayerMove();

        if (checkWin()) {
            displayBoard();
            cout << "Player " << currentPlayer << " wins! Congratulations!\n";
            break;
        }

        if (checkDraw()) {
            displayBoard();
            cout << "It's a draw! Well played both!\n";
            break;
        }

        switchPlayer();
    }
    return 0;
}