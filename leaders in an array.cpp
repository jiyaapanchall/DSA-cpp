#include <iostream>
#include <vector>
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

    vector<int> leaders;

    int maxRight = arr[n - 1];

    // Last element is always a leader
    leaders.push_back(maxRight);

    // Traverse from right to left
    for (int i = n - 2; i >= 0; i--) {

        if (arr[i] > maxRight) {
            leaders.push_back(arr[i]);
            maxRight = arr[i];
        }
    }

    cout << "\nLeaders in the array:\n";

    // Leaders were collected from right to left,
    // so print them in reverse order.
    for (int i = leaders.size() - 1; i >= 0; i--) {
        cout << leaders[i] << " ";
    }

    return 0;
}s