#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    vector<vector<int>> ans;

    void backtrack(vector<int>& candidates,
                   int target,
                   int start,
                   vector<int>& current) {

        // Target reached
        if (target == 0) {
            ans.push_back(current);
            return;
        }

        // Try candidates from start
        for (int i = start; i < candidates.size(); i++) {

            // Candidate is too large
            if (candidates[i] > target)
                continue;

            // Choose
            current.push_back(candidates[i]);

            // Explore
            // i, NOT i + 1
            // because we can reuse the same number
            backtrack(candidates,
                      target - candidates[i],
                      i,
                      current);

            // Undo
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(
        vector<int>& candidates,
        int target) {

        vector<int> current;

        backtrack(candidates,
                  target,
                  0,
                  current);

        return ans;
    }
};

int main() {

    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    Solution sol;

    vector<vector<int>> result =
        sol.combinationSum(candidates, target);

    for (auto& combination : result) {

        cout << "[ ";

        for (int x : combination)
            cout << x << " ";

        cout << "]\n";
    }

    return 0;
}