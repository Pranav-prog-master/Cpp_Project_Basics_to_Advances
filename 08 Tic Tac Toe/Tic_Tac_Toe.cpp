#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <string>

using namespace std;

class TicTacToe {
private:
    char board[3][3];
    int difficulty;
    int playerScore;
    int computerScore;
    int drawScore;
    const char PLAYER_X = 'X';
    const char COMPUTER_O = 'O';
    const int BOARD_SIZE = 3;

    // ✅ Safe clear screen
    void clearScreen() {
#ifdef _WIN32
        system("cls");  // Windows
#else
        cout << "\033[H\033[2J";
        cout.flush();
#endif
    }

    void resetBoard() {
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                board[i][j] = ' ';
            }
        }
    }

    void printBoard() {
        clearScreen();
        cout << "Score - Player (X): " << playerScore
             << " | Computer (O): " << computerScore
             << " | Draws: " << drawScore << "\n";
        cout << "-------------------\n";
        cout << "   Tic-Tac-Toe\n\n";

        for (int i = 0; i < BOARD_SIZE; i++) {
            cout << "     ";
            for (int j = 0; j < BOARD_SIZE; j++) {
                cout << " " << board[i][j] << " ";
                if (j < BOARD_SIZE - 1) cout << "|";
            }
            if (i < BOARD_SIZE - 1) cout << "\n     ---+---+---";
            cout << "\n";
        }
        cout << "\n";
    }

    bool isValidMove(int row, int col) {
        return row >= 0 && row < BOARD_SIZE &&
               col >= 0 && col < BOARD_SIZE &&
               board[row][col] == ' ';
    }

    bool checkWin(char player) {
        for (int i = 0; i < BOARD_SIZE; i++) {
            if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
                (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
                return true;
            }
        }
        return (board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
               (board[0][2] == player && board[1][1] == player && board[2][0] == player);
    }

    bool checkDraw() {
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == ' ') return false;
            }
        }
        return true;
    }

    void playerMove() {
        int row, col;
        do {
            cout << "\nPlayer X's turn.\nEnter row and column (1-3): ";
            while (!(cin >> row >> col)) {
                cout << "Invalid input. Enter two numbers: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            row--; col--;
            if (!isValidMove(row, col)) {
                cout << "Invalid move. Try again.\n";
            }
        } while (!isValidMove(row, col));
        board[row][col] = PLAYER_X;
    }

    void computerMove() {
        // 1. Winning move
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = COMPUTER_O;
                    if (checkWin(COMPUTER_O)) return;
                    board[i][j] = ' ';
                }
            }
        }
        // 2. Block player
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = PLAYER_X;
                    if (checkWin(PLAYER_X)) {
                        board[i][j] = COMPUTER_O;
                        return;
                    }
                    board[i][j] = ' ';
                }
            }
        }
        // 3. God mode: center/corners
        if (difficulty == 2) {
            if (board[1][1] == ' ') { board[1][1] = COMPUTER_O; return; }
            int corners[4][2] = {{0,0},{0,2},{2,0},{2,2}};
            for (auto &corner : corners) {
                if (board[corner[0]][corner[1]] == ' ') {
                    board[corner[0]][corner[1]] = COMPUTER_O;
                    return;
                }
            }
        }
        // 4. Default random move
        int row, col;
        do {
            row = rand() % BOARD_SIZE;
            col = rand() % BOARD_SIZE;
        } while (board[row][col] != ' ');
        board[row][col] = COMPUTER_O;
    }

    void playGame() {
        resetBoard();
        char currentPlayer = (rand() % 2 == 0) ? PLAYER_X : COMPUTER_O;

        while (true) {
            printBoard();
            if (currentPlayer == PLAYER_X) {
                playerMove();
                if (checkWin(PLAYER_X)) {
                    playerScore++;
                    printBoard();
                    cout << "Congratulations! You have won!!!\n";
                    break;
                }
                currentPlayer = COMPUTER_O;
            } else {
                cout << "Computer's turn (O)...\n";
                computerMove();
                if (checkWin(COMPUTER_O)) {
                    computerScore++;
                    printBoard();
                    cout << "I won!!! But you played well...\n";
                    break;
                }
                currentPlayer = PLAYER_X;
            }
            if (checkDraw()) {
                drawScore++;
                printBoard();
                cout << "\nIt's a draw!\n";
                break;
            }
        }
    }

public:
    TicTacToe() {
        srand(time(nullptr));
        playerScore = 0;
        computerScore = 0;
        drawScore = 0;
    }

    void start() {
        cout << "\nSelect difficulty level:\n";
        cout << "1. Human (Standard)\n";
        cout << "2. God (Impossible to win)\n";
        cout << "Enter your choice: ";
        while (!(cin >> difficulty) || (difficulty != 1 && difficulty != 2)) {
            cout << "Invalid input. Please enter 1 or 2: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int playAgain = 1;
        do {
            playGame();
            cout << "\nPlay again? (1 for yes, 0 for no): ";
            while (!(cin >> playAgain) || (playAgain != 0 && playAgain != 1)) {
                cout << "Invalid input. Enter 1 or 0: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (playAgain == 1);

        cout << "\nBye Bye, thanks for playing.\n";
    }
};

int main() {
    TicTacToe game;
    game.start();
    return 0;
}
