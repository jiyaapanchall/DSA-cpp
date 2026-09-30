#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

bool canPartition(vector<int>& nums) {

    int totalSum = accumulate(nums.begin(), nums.end(), 0);

    // Equal partition is impossible if total is odd
    if (totalSum % 2 != 0)
        return false;

    int target = totalSum / 2;

    vector<bool> dp(target + 1, false);

    dp[0] = true;

    for (int num : nums) {

        for (int sum = target; sum >= num; sum--) {

            dp[sum] = dp[sum] || dp[sum - num];
        }
    }

    return dp[target];
}

int main() {

    vector<int> nums = {1, 5, 11, 5};

    if (canPartition(nums))
        cout << "true";
    else
        cout << "false";

    return 0;
}