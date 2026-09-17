#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {

    // Step 1: Count frequency
    unordered_map<int, int> freq;

    for (int num : nums) {
        freq[num]++;
    }

    // Min heap: {frequency, element}
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > minHeap;

    // Step 2: Keep only k most frequent elements
    for (auto& [num, count] : freq) {

        minHeap.push({count, num});

        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    // Step 3: Store answer
    vector<int> result;

    while (!minHeap.empty()) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }

    return result;
}

int main() {

    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    vector<int> result = topKFrequent(nums, k);

    cout << "Top " << k << " frequent elements: ";

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}