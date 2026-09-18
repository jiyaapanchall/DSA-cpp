#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {

    int write = 0;

    // Move all non-zero elements forward
    for (int read = 0; read < nums.size(); read++) {

        if (nums[read] != 0) {
            nums[write] = nums[read];
            write++;
        }
    }

    // Fill remaining positions with zero
    while (write < nums.size()) {
        nums[write] = 0;
        write++;
    }
}

int main() {

    vector<int> nums = {0, 1, 0, 3, 12};

    moveZeroes(nums);

    for (int x : nums) {
        cout << x << " ";
    }

    return 0;
}