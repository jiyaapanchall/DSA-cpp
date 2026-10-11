
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int dr[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dc[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

    bool solve(int row, int col, int moveNumber,
               vector<vector<int>>& board, int N) {

        // Every square has been visited
        if (moveNumber == N * N)
            return true;

        for (int i = 0; i < 8; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];

            if (nr >= 0 && nr < N &&
                nc >= 0 && nc < N &&
                board[nr][nc] == -1) {

                // Choose
                board[nr][nc] = moveNumber + 1;

                // Explore
                if (solve(nr, nc, moveNumber + 1,
                          board, N)) {
                    return true;
                }

                // Undo
                board[nr][nc] = -1;
            }
        }

        return false;
    }

public:
    bool knightTour(int N) {
        if (N <= 0)
            return false;

        vector<vector<int>> board(
            N, vector<int>(N, -1)
        );

        board[0][0] = 0;

        if (!solve(0, 0, 0, board, N))
            return false;

        cout << "Knight's Tour:\n";

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << board[i][j] << "\t";
            }
            cout << '\n';
        }

        return true;
    }
};

int main() {
    int N = 5;

    Solution sol;

    if (!sol.knightTour(N))
        cout << "No tour found\n";

    return 0;
}
