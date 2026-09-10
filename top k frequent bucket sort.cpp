#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {

    // Count frequency
    unordered_map<int, int> freq;

    for (int num : nums) {
        freq[num]++;
    }

    // buckets[i] contains elements appearing i times
    vector<vector<int>> buckets(nums.size() + 1);

    for (auto& [num, count] : freq) {
        buckets[count].push_back(num);
    }

    // Collect from highest frequency
    vector<int> result;

    for (int i = buckets.size() - 1; i >= 0 && result.size() < k; i--) {

        for (int num : buckets[i]) {

            result.push_back(num);

            if (result.size() == k) {
                break;
            }
        }
    }

    return result;
}

int main() {

    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    vector<int> result = topKFrequent(nums, k);

    cout << "Top " << k << " frequent elements: ";

    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}