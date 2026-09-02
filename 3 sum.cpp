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

    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n - 2; i++) {

        // Skip duplicate first elements
        if (i > 0 && arr[i] == arr[i - 1]) {
            continue;
        }

        int left = i + 1;
        int right = n - 1;

        while (left < right) {

            int sum = arr[i] + arr[left] + arr[right];

            if (sum == 0) {

                ans.push_back({
                    arr[i],
                    arr[left],
                    arr[right]
                });

                left++;
                right--;

                // Skip duplicate left values
                while (left < right &&
                       arr[left] == arr[left - 1]) {
                    left++;
                }

                // Skip duplicate right values
                while (left < right &&
                       arr[right] == arr[right + 1]) {
                    right--;
                }
            }

            else if (sum < 0) {
                left++;
            }

            else {
                right--;
            }
        }
    }

    cout << "\nTriplets with sum 0:\n";

    for (auto triplet : ans) {

        cout << "[";

        for (int i = 0; i < 3; i++) {

            cout << triplet[i];

            if (i < 2) {
                cout << ", ";
            }
        }

        cout << "] ";
    }

    return 0;
}