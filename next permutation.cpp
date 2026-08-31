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

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Step 1: Find breakpoint
    int i = n - 2;

    while (i >= 0 && arr[i] >= arr[i + 1]) {
        i--;
    }

    // Step 2: If breakpoint exists,
    // find the next greater element
    if (i >= 0) {

        int j = n - 1;

        while (arr[j] <= arr[i]) {
            j--;
        }

        swap(arr[i], arr[j]);
    }

    // Step 3: Reverse the suffix
    reverse(arr.begin() + i + 1, arr.end());

    cout << "\nNext permutation:\n";

    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}