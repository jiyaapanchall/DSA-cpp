#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longestSubarray(vector<int>& nums, int K) {

    unordered_map<int, int> mp;

    int prefixSum = 0;
    int maxLength = 0;

    for (int i = 0; i < nums.size(); i++) {

        prefixSum += nums[i];

        // Entire array from 0 to i
        if (prefixSum == K) {
            maxLength = i + 1;
        }

        // Check if needed prefix exists
        if (mp.find(prefixSum - K) != mp.end()) {

            int length = i - mp[prefixSum - K];

            maxLength = max(maxLength, length);
        }

        // Store first occurrence only
        if (mp.find(prefixSum) == mp.end()) {
            mp[prefixSum] = i;
        }
    }

    return maxLength;
}

int main() {

    vector<int> nums = {1,2,3,1,1,1,1};

    int K = 6;

    cout << "Longest Length: "
         << longestSubarray(nums, K);

    return 0;
}