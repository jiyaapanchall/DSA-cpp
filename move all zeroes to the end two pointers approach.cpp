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

    int j = 0;

    // Move all non-zero elements to the front
    for (int i = 0; i < n; i++) {

        if (arr[i] != 0) {
            arr[j] = arr[i];
            j++;
        }
    }

    // Fill remaining positions with zero
    while (j < n) {
        arr[j] = 0;
        j++;
    }

    cout << "\nArray after moving zeros to the end:\n";

    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}