#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {

    int n = nums.size();

    if (n <= 2)
        return n;

    int write = 2;

    for (int read = 2; read < n; read++) {

        if (nums[read] != nums[write - 2]) {
            nums[write] = nums[read];
            write++;
        }
    }

    return write;
}

int main() {

    vector<int> nums = {1, 1, 1, 2, 2, 3};

    int k = removeDuplicates(nums);

    cout << "New length: " << k << endl;

    cout << "Array: ";

    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}