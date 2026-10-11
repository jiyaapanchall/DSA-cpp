
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses,
                   vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // Build the graph
        for (const auto& p : prerequisites) {
            int course = p[0];
            int prerequisite = p[1];

            adj[prerequisite].push_back(course);
            indegree[course]++;
        }

        // Add courses with no prerequisites
        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int completed = 0;

        // Process courses using BFS
        while (!q.empty()) {
            int course = q.front();
            q.pop();

            completed++;

            for (int next : adj[course]) {
                indegree[next]--;

                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        // All courses must be completed
        return completed == numCourses;
    }
};

int main() {
    int numCourses = 2;
    vector<vector<int>> prerequisites = {
        {1, 0}
    };

    Solution sol;

    if (sol.canFinish(numCourses, prerequisites))
        cout << "All courses can be completed\n";
    else
        cout << "Courses cannot all be completed\n";

    return 0;
}
