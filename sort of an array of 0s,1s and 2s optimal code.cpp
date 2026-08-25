#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements (0, 1 or 2):\n";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int low = 0;
    int mid = 0;
    int high = n - 1;

    while (mid <= high) {

        if (arr[mid] == 0) {

            swap(arr[low], arr[mid]);

            low++;
            mid++;
        }

        else if (arr[mid] == 1) {

            mid++;
        }

        else {

            swap(arr[mid], arr[high]);

            high--;
        }
    }

    cout << "\nSorted array:\n";

    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}