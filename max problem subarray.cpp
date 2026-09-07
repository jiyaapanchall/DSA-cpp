#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProductSubarray(vector<int>& nums) {

    int maxProduct = nums[0];
    int minProduct = nums[0];

    int answer = nums[0];

    for (int i = 1; i < nums.size(); i++) {

        int num = nums[i];

        int oldMax = maxProduct;
        int oldMin = minProduct;

        maxProduct = max({
            num,
            num * oldMax,
            num * oldMin
        });

        minProduct = min({
            num,
            num * oldMax,
            num * oldMin
        });

        answer = max(answer, maxProduct);
    }

    return answer;
}

int main() {

    vector<int> nums = {2, 3, -2, 4};

    cout << "Maximum product: "
         << maxProductSubarray(nums) << endl;

    return 0;
}