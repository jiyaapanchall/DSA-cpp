#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySum(vector<int>& nums, int k) {

    unordered_map<int, int> prefixCount;

    // Empty prefix
    prefixCount[0] = 1;

    int sum = 0;
    int count = 0;

    for (int num : nums) {

        sum += num;

        // Check how many previous prefix sums equal sum - k
        if (prefixCount.find(sum - k) != prefixCount.end()) {
            count += prefixCount[sum - k];
        }

        // Store current prefix sum
        prefixCount[sum]++;
    }

    return count;
}

int main() {

    vector<int> nums = {1, 2, 3};

    int k = 3;

    cout << "Number of subarrays: "
         << subarraySum(nums, k);

    return 0;
}