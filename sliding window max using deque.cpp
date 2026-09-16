#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> answer;
    deque<int> dq;  // Stores indices

    for (int i = 0; i < nums.size(); i++) {

        // Remove indices outside the current window
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // Remove smaller elements from the back
        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }

        // Add current index
        dq.push_back(i);

        // Start storing answers when first window is complete
        if (i >= k - 1) {
            answer.push_back(nums[dq.front()]);
        }
    }

    return answer;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> result = maxSlidingWindow(nums, k);

    cout << "Maximum of each window: ";

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}