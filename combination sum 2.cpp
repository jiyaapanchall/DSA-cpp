#include <iostream>
#include <vector>
#include <algorithm>
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

        for (int i = start; i < candidates.size(); i++) {

            // Since array is sorted
            if (candidates[i] > target)
                break;

            // Skip duplicate choices
            // at the same recursion level
            if (i > start &&
                candidates[i] == candidates[i - 1])
                continue;

            // Choose
            current.push_back(candidates[i]);

            // Explore
            // i + 1 because each element
            // can be used only once
            backtrack(candidates,
                      target - candidates[i],
                      i + 1,
                      current);

            // Undo
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(
        vector<int>& candidates,
        int target) {

        sort(candidates.begin(), candidates.end());

        vector<int> current;

        backtrack(candidates,
                  target,
                  0,
                  current);

        return ans;
    }
};

int main() {

    vector<int> candidates =
        {10, 1, 2, 7, 6, 1, 5};

    int target = 8;

    Solution sol;

    vector<vector<int>> result =
        sol.combinationSum2(candidates, target);

    for (auto& combination : result) {

        cout << "[ ";

        for (int x : combination)
            cout << x << " ";

        cout << "]\n";
    }

    return 0;
}