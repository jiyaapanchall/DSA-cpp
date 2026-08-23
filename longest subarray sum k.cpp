#include <iostream>
#include <vector>
#include <unordered_map>
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

    cout << "Enter K: ";
    cin >> k;

    unordered_map<int, int> prefixSum;

    int sum = 0;
    int maxLength = 0;

    for (int i = 0; i < n; i++) {

        sum += arr[i];

        // If subarray starts from index 0
        if (sum == k) {
            maxLength = i + 1;
        }

        // Check whether sum - k appeared before
        if (prefixSum.find(sum - k) != prefixSum.end()) {

            int length = i - prefixSum[sum - k];

            maxLength = max(maxLength, length);
        }

        // Store only the first occurrence
        if (prefixSum.find(sum) == prefixSum.end()) {
            prefixSum[sum] = i;
        }
    }

    cout << "\nLongest subarray length = " << maxLength;

    return 0;
}