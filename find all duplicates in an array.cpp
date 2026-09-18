#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

vector<int> findDuplicates(vector<int>& nums) {

    vector<int> duplicates;

    for (int i = 0; i < nums.size(); i++) {

        int value = abs(nums[i]);
        int index = value - 1;

        if (nums[index] < 0) {
            // Already visited → duplicate
            duplicates.push_back(value);
        }
        else {
            // Mark as visited
            nums[index] = -nums[index];
        }
    }

    return duplicates;
}

int main() {

    vector<int> nums = {
        4, 3, 2, 7, 8, 2, 3, 1
    };

    vector<int> result = findDuplicates(nums);

    cout << "Duplicates: ";

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}