
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    bool isSafe(int node,
                int color,
                vector<vector<int>>& graph,
                vector<int>& colors,
                int V) {

        for (int neighbour = 0;
             neighbour < V;
             neighbour++) {

            if (graph[node][neighbour] == 1 &&
                colors[neighbour] == color) {
                return false;
            }
        }

        return true;
    }

    bool solve(int node,
               vector<vector<int>>& graph,
               vector<int>& colors,
               int V,
               int M) {

        // All vertices have been colored
        if (node == V)
            return true;

        // Try each available color
        for (int color = 1; color <= M; color++) {

            if (isSafe(node, color, graph, colors, V)) {

                // Choose
                colors[node] = color;

                // Explore
                if (solve(node + 1, graph, colors, V, M))
                    return true;

                // Undo
                colors[node] = 0;
            }
        }

        // No color works for this vertex
        return false;
    }

    bool graphColoring(vector<vector<int>>& graph,
                       int M,
                       int V) {

        vector<int> colors(V, 0);

        return solve(0, graph, colors, V, M);
    }
};

int main() {

    int V = 3;
    int M = 3;

    vector<vector<int>> graph = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}
    };

    Solution sol;

    if (sol.graphColoring(graph, M, V))
        cout << "Coloring is possible" << endl;
    else
        cout << "Coloring is not possible" << endl;

    return 0;
}
