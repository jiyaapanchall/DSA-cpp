
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
private:
    void solve(int row, int col,
               vector<vector<int>>& maze,
               int n,
               vector<vector<int>>& visited,
               string& path,
               vector<string>& ans) {

        // Destination reached
        if (row == n - 1 && col == n - 1) {
            ans.push_back(path);
            return;
        }

        // Mark current cell as visited
        visited[row][col] = 1;

        // D, L, R, U gives lexicographical path order
        int dr[] = {1, 0, 0, -1};
        int dc[] = {0, -1, 1, 0};
        char direction[] = {'D', 'L', 'R', 'U'};

        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];

            if (nr >= 0 && nr < n &&
                nc >= 0 && nc < n &&
                maze[nr][nc] == 1 &&
                visited[nr][nc] == 0) {

                path.push_back(direction[i]);

                solve(nr, nc, maze, n,
                      visited, path, ans);

                // Backtrack
                path.pop_back();
            }
        }

        // Allow this cell to be used by another path
        visited[row][col] = 0;
    }

public:
    vector<string> findPath(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<string> ans;

        if (n == 0 || maze[0][0] == 0 ||
            maze[n - 1][n - 1] == 0) {
            return ans;
        }

        vector<vector<int>> visited(
            n, vector<int>(n, 0)
        );

        string path;
        solve(0, 0, maze, n, visited, path, ans);

        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    Solution sol;
    vector<string> paths = sol.findPath(maze);

    if (paths.empty()) {
        cout << "No path found\n";
    } else {
        for (const string& p : paths) {
            cout << p << '\n';
        }
    }

    return 0;
}
