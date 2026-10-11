
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int rows, cols;

    bool dfs(vector<vector<char>>& board,
             string& word,
             int r, int c,
             int index) {

        // Every character matched
        if (index == word.size())
            return true;

        // Out of bounds
        if (r < 0 || c < 0 ||
            r >= rows || c >= cols)
            return false;

        // Wrong character or already visited
        if (board[r][c] != word[index])
            return false;

        // Mark this cell as visited
        char original = board[r][c];
        board[r][c] = '#';

        // Explore four directions
        bool found =
            dfs(board, word, r + 1, c, index + 1) ||
            dfs(board, word, r - 1, c, index + 1) ||
            dfs(board, word, r, c + 1, index + 1) ||
            dfs(board, word, r, c - 1, index + 1);

        // Undo the visit
        board[r][c] = original;

        return found;
    }

    bool exist(vector<vector<char>>& board,
               string word) {

        rows = board.size();
        cols = board[0].size();

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (dfs(board, word, r, c, 0))
                    return true;
            }
        }

        return false;
    }
};

int main() {
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };

    string word = "ABCC";

    Solution sol;
    cout << boolalpha << sol.exist(board, word)
         << endl;

    return 0;
}
