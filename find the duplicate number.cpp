#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int>& nums) {

    // Phase 1: Find intersection point
    int slow = nums[0];
    int fast = nums[0];

    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    // Phase 2: Find entrance of cycle
    slow = nums[0];

    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}

int main() {

    vector<int> nums = {1, 3, 4, 2, 2};

    cout << "Duplicate Number: "
         << findDuplicate(nums);

    return 0;
}