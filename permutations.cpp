#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    vector<vector<int>> ans;

    void backtrack(vector<int>& nums,
                   vector<int>& current,
                   vector<bool>& used) {

        // If permutation is complete
        if (current.size() == nums.size()) {
            ans.push_back(current);
            return;
        }

        // Try every number
        for (int i = 0; i < nums.size(); i++) {

            // Already used
            if (used[i])
                continue;

            // Choose
            used[i] = true;
            current.push_back(nums[i]);

            // Explore
            backtrack(nums, current, used);

            // Undo
            current.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<int> current;
        vector<bool> used(nums.size(), false);

        backtrack(nums, current, used);

        return ans;
    }
};

int main() {

    vector<int> nums = {1, 2, 3};

    Solution sol;

    vector<vector<int>> result = sol.permute(nums);

    for (auto& permutation : result) {

        for (int x : permutation)
            cout << x << " ";

        cout << endl;
    }

    return 0;
}