#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int robLinear(vector<int>& nums, int start, int end) {
    int prev2 = 0;
    int prev1 = 0;

    for (int i = start; i <= end; i++) {
        int robCurrent = prev2 + nums[i];
        int skipCurrent = prev1;

        int current = max(robCurrent, skipCurrent);

        prev2 = prev1;
        prev1 = current;
    }

    return prev1;
}

int rob(vector<int>& nums) {
    int n = nums.size();

    if (n == 1)
        return nums[0];

    int case1 = robLinear(nums, 0, n - 2);
    int case2 = robLinear(nums, 1, n - 1);

    return max(case1, case2);
}

int main() {
    vector<int> nums = {2, 3, 2};

    cout << rob(nums);

    return 0;
}