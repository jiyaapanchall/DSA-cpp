#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

vector<int> findErrorNums(vector<int>& nums) {

    int repeated = -1;
    int missing = -1;

    // Find repeated number
    for (int i = 0; i < nums.size(); i++) {

        int value = abs(nums[i]);
        int index = value - 1;

        if (nums[index] < 0) {
            repeated = value;
        } else {
            nums[index] = -nums[index];
        }
    }

    // Find missing number
    for (int i = 0; i < nums.size(); i++) {

        if (nums[i] > 0) {
            missing = i + 1;
            break;
        }
    }

    return {repeated, missing};
}

int main() {

    vector<int> nums = {1, 2, 2, 4};

    vector<int> result = findErrorNums(nums);

    cout << "Repeated number: " << result[0] << endl;
    cout << "Missing number: " << result[1] << endl;

    return 0;
}