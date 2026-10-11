
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(vector<int>& nums,
                   int start,
                   vector<int>& current) {

        // Every current selection is a valid subset
        ans.push_back(current);

        for (int i = start; i < nums.size(); i++) {

            // Skip duplicates at this recursion level
            if (i > start && nums[i] == nums[i - 1])
                continue;

            // Choose
            current.push_back(nums[i]);

            // Explore remaining elements
            backtrack(nums, i + 1, current);

            // Undo
            current.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> current;
        backtrack(nums, 0, current);

        return ans;
    }
};

int main() {
    vector<int> nums = {1, 2, 2};

    Solution sol;
    vector<vector<int>> result = sol.subsetsWithDup(nums);

    for (const auto& subset : result) {
        cout << "[ ";
        for (int x : subset)
            cout << x << " ";
        cout << "]\n";
    }

    return 0;
}
