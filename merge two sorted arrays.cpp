#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n, m;

    cout << "Enter size of first array: ";
    cin >> n;

    vector<int> arr1(n);

    cout << "Enter sorted elements of first array:\n";

    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    cout << "Enter size of second array: ";
    cin >> m;

    vector<int> arr2(m);

    cout << "Enter sorted elements of second array:\n";

    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    vector<int> result;

    int i = 0;
    int j = 0;

    // Compare elements from both arrays
    while (i < n && j < m) {

        if (arr1[i] <= arr2[j]) {
            result.push_back(arr1[i]);
            i++;
        }
        else {
            result.push_back(arr2[j]);
            j++;
        }
    }

    // Add remaining elements of first array
    while (i < n) {
        result.push_back(arr1[i]);
        i++;
    }

    // Add remaining elements of second array
    while (j < m) {
        result.push_back(arr2[j]);
        j++;
    }

    cout << "\nMerged sorted array:\n";

    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}