#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    bool isValid(vector<vector<char>>& board,
                 int row,
                 int col,
                 char num) {

        // Check row
        for (int j = 0; j < 9; j++) {
            if (board[row][j] == num)
                return false;
        }

        // Check column
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == num)
                return false;
        }

        // Check 3 x 3 box
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;

        for (int i = startRow;
             i < startRow + 3;
             i++) {

            for (int j = startCol;
                 j < startCol + 3;
                 j++) {

                if (board[i][j] == num)
                    return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board) {

        for (int row = 0; row < 9; row++) {

            for (int col = 0; col < 9; col++) {

                // Skip filled cells
                if (board[row][col] != '.')
                    continue;

                // Try digits 1 to 9
                for (char num = '1';
                     num <= '9';
                     num++) {

                    if (isValid(board, row, col, num)) {

                        // Choose
                        board[row][col] = num;

                        // Explore
                        if (solve(board))
                            return true;

                        // Undo
                        board[row][col] = '.';
                    }
                }

                // No number works
                return false;
            }
        }

        // Entire board solved
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

int main() {

    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    Solution sol;

    sol.solveSudoku(board);

    for (auto& row : board) {

        for (char c : row) {
            cout << c << " ";
        }

        cout << '\n';
    }

    return 0;
}