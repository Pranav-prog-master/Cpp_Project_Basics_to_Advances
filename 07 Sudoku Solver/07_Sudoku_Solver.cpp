#include <iostream>
#include <vector>

using namespace std;

class SudokuSolver {
private:
    int puzzle[9][9];

    bool is_valid_move(int row, int col, int val) {
        for (int i = 0; i < 9; ++i) {
            if (puzzle[row][i] == val) {
                return false;
            }
        }

        for (int i = 0; i < 9; ++i) {
            if (puzzle[i][col] == val) {
                return false;
            }
        }

        int startRow = row - row % 3;
        int startCol = col - col % 3;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (puzzle[i + startRow][j + startCol] == val) {
                    return false;
                }
            }
        }
        return true;
    }

    bool solve_recursive(int row, int col) {
        if (col == 9) {
            if (row == 8) {
                return true; 
            }
            row++;
            col = 0;
        }

        if (puzzle[row][col] > 0) {
            return solve_recursive(row, col + 1);
        }

        for (int val = 1; val <= 9; ++val) {
            if (is_valid_move(row, col, val)) {
                puzzle[row][col] = val;
                if (solve_recursive(row, col + 1)) {
                    return true;
                }
                puzzle[row][col] = 0; 
            }
        }
        return false;
    }

public:
    SudokuSolver(int initial_puzzle[9][9]) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                puzzle[i][j] = initial_puzzle[i][j];
            }
        }
    }

    bool solve() {
        return solve_recursive(0, 0);
    }

    void print_puzzle() {
        cout << "\n+-------+-------+-------+" << endl;
        for (int row = 0; row < 9; ++row) {
            if (row % 3 == 0 && row != 0) {
                cout << "|-------+-------+-------|" << endl;
            }
            for (int col = 0; col < 9; ++col) {
                if (col % 3 == 0) {
                    cout << "| ";
                }
                if (puzzle[row][col] != 0) {
                    cout << puzzle[row][col] << " ";
                } else {
                    cout << "  ";
                }
            }
            cout << "|" << endl;
        }
        cout << "+-------+-------+-------+" << endl;
    }
};

int main() {
    int initial_puzzle[9][9] = {
        {3,0,0,0,2,0,0,7,0},
        {9,0,0,5,0,0,0,1,4},
        {0,1,6,3,7,0,0,0,8},
        {2,0,0,8,0,0,0,0,1},
        {5,0,0,0,4,1,8,0,0},
        {0,8,9,0,0,0,0,5,0},
        {0,0,5,0,1,0,2,8,0},
        {0,4,0,0,0,6,0,9,3},
        {7,3,1,0,8,2,0,0,0},
    };

    SudokuSolver solver(initial_puzzle);

    cout << "\n\tWelcome to SUDOKU Solver !!!" << endl;
    cout << "\nOriginal Puzzle:";
    solver.print_puzzle();

    if (solver.solve()) {
        cout << "\nThe puzzle is solved: ";
        solver.print_puzzle();
    } else {
        cout << "\nThis puzzle is not Solvable" << endl;
    }

    return 0;
}
