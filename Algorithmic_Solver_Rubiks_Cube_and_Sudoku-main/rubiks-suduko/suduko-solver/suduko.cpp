#include <iostream>
#include <vector>

using namespace std;
bool isValid(vector<vector<char>> &board, int row, int col, char c) {
    for (int i = 0; i < 9; i++) {
        // Check row
        if (board[row][i] == c) return false;
        // Check column
        if (board[i][col] == c) return false;
        // Check 3x3 sub-box
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;
    }
    return true;
}


bool solveSudoku(vector<vector<char>> &board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] == '.') {
                for (char c = '1'; c <= '9'; c++) {
                    if (isValid(board, i, j, c)) {
                        board[i][j] = c;
                        if (solveSudoku(board)) return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void printBoard(const vector<vector<char>> &board) {
    for (int i = 0; i < 9; i++) {
        if (i > 0 && i % 3 == 0) {
            cout << "------+-------+------\n";
        }
        for (int j = 0; j < 9; j++) {
            if (j > 0 && j % 3 == 0) {
                cout << "| ";
            }
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}
int main() {
    vector<vector<char>> board{
        {'.', '5', '.', '.', '.', '.', '.', '.', '9'},
        {'3', '4', '.', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '2', '.', '.', '.', '.'},
        {'.', '.', '.', '6', '.', '.', '.', '.', '.'},
        {'.', '9', '.', '.', '3', '.', '1', '.', '.'},
        {'.', '.', '.', '.', '.', '9', '5', '.', '3'},
        {'4', '.', '.', '.', '.', '8', '.', '.', '1'},
        {'.', '.', '.', '3', '.', '2', '.', '7', '8'},
        {'6', '.', '.', '.', '.', '.', '.', '4', '.'}
    };

    if (solveSudoku(board)) {
        printBoard(board);
    } else {
        cout << "No solution exists.\n";
    }

    return 0;
}