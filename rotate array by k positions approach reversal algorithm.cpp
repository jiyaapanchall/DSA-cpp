#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int n, k;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements:\n";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter k: ";
    cin >> k;

    k = k % n;

    // Step 1: Reverse entire array
    reverse(arr.begin(), arr.end());

    // Step 2: Reverse first k elements
    reverse(arr.begin(), arr.begin() + k);

    // Step 3: Reverse remaining elements
    reverse(arr.begin() + k, arr.end());

    cout << "\nRotated array:\n";

    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}