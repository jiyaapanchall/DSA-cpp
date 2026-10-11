
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int rows, cols;

    void dfs(vector<vector<char>>& grid, int r, int c) {
        // Out of bounds or water
        if (r < 0 || r >= rows ||
            c < 0 || c >= cols ||
            grid[r][c] == '0') {
            return;
        }

        // Mark this land cell as visited
        grid[r][c] = '0';

        // Explore four directions
        dfs(grid, r - 1, c);
        dfs(grid, r + 1, c);
        dfs(grid, r, c - 1);
        dfs(grid, r, c + 1);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;

        rows = grid.size();
        cols = grid[0].size();

        int islands = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '1') {
                    islands++;
                    dfs(grid, r, c);
                }
            }
        }

        return islands;
    }
};

int main() {
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    Solution sol;
    cout << "Number of islands: "
         << sol.numIslands(grid) << '\n';

    return 0;
}
