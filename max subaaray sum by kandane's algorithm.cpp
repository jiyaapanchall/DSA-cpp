#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements:\n";

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int currentSum = arr[0];
    int maxSum = arr[0];

    for(int i = 1; i < n; i++) {

        currentSum = max(arr[i], currentSum + arr[i]);

        maxSum = max(maxSum, currentSum);
    }

    cout << "\nMaximum Subarray Sum = " << maxSum;

    return 0;
}