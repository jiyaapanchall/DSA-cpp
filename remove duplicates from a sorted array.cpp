#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter sorted array elements:\n";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (n == 0) {
        cout << "Array is empty.";
        return 0;
    }

    int i = 0;

    for (int j = 1; j < n; j++) {

        if (arr[j] != arr[i]) {

            i++;
            arr[i] = arr[j];
        }
    }

    int uniqueCount = i + 1;

    cout << "\nArray after removing duplicates:\n";

    for (int j = 0; j < uniqueCount; j++) {
        cout << arr[j] << " ";
    }

    cout << "\nNumber of unique elements = "
         << uniqueCount;

    return 0;
}