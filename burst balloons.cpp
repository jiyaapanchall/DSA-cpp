#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxCoins(vector<int>& nums) {
    int n = nums.size();

    vector<int> arr(n + 2, 1);

    for (int i = 0; i < n; i++) {
        arr[i + 1] = nums[i];
    }

    vector<vector<int>> dp(
        n + 2,
        vector<int>(n + 2, 0)
    );

    // Length of the interval
    for (int len = 2; len < n + 2; len++) {

        for (int left = 0;
             left + len < n + 2;
             left++) {

            int right = left + len;

            for (int k = left + 1;
                 k < right;
                 k++) {

                int coins =
                    dp[left][k] +
                    dp[k][right] +
                    arr[left] * arr[k] * arr[right];

                dp[left][right] =
                    max(dp[left][right], coins);
            }
        }
    }

    return dp[0][n + 1];
}

int main() {
    vector<int> nums = {3, 1, 5, 8};

    cout << maxCoins(nums);

    return 0;
}