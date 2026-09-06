#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int findKthSmallest(vector<int>& nums, int k) {

    // Max Heap
    priority_queue<int> maxHeap;

    for (int num : nums) {

        maxHeap.push(num);

        // Keep only K smallest elements
        if (maxHeap.size() > k) {
            maxHeap.pop();
        }
    }

    return maxHeap.top();
}

int main() {

    vector<int> nums = {7, 10, 4, 3, 20, 15};

    int k = 3;

    cout << "Kth smallest element: "
         << findKthSmallest(nums, k) << endl;

    return 0;
}