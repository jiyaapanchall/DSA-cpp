#include <iostream>
#include <vector>
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

    // Handle k greater than n
    k = k % n;

    vector<int> result(n);

    for (int i = 0; i < n; i++) {
        result[(i + k) % n] = arr[i];
    }

    cout << "\nRotated array:\n";

    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }

    return 0;
}