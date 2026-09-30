#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int findTargetSumWays(vector<int>& nums, int target) {

    int totalSum = accumulate(nums.begin(), nums.end(), 0);

    // Impossible cases
    if (abs(target) > totalSum)
        return 0;

    if ((totalSum + target) % 2 != 0)
        return 0;

    int subsetSum = (totalSum + target) / 2;

    vector<int> dp(subsetSum + 1, 0);

    dp[0] = 1;

    for (int num : nums) {

        for (int sum = subsetSum; sum >= num; sum--) {

            dp[sum] += dp[sum - num];
        }
    }

    return dp[subsetSum];
}

int main() {

    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;

    cout << findTargetSumWays(nums, target);

    return 0;
}