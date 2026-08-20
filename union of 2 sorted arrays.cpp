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

    vector<int> unionArray;

    int i = 0;
    int j = 0;

    while (i < n && j < m) {

        if (arr1[i] < arr2[j]) {

            // Add only if different from last added element
            if (unionArray.empty() ||
                unionArray.back() != arr1[i]) {

                unionArray.push_back(arr1[i]);
            }

            i++;
        }

        else if (arr1[i] > arr2[j]) {

            if (unionArray.empty() ||
                unionArray.back() != arr2[j]) {

                unionArray.push_back(arr2[j]);
            }

            j++;
        }

        else {

            // Both elements are equal
            if (unionArray.empty() ||
                unionArray.back() != arr1[i]) {

                unionArray.push_back(arr1[i]);
            }

            i++;
            j++;
        }
    }

    // Remaining elements of first array
    while (i < n) {

        if (unionArray.empty() ||
            unionArray.back() != arr1[i]) {

            unionArray.push_back(arr1[i]);
        }

        i++;
    }

    // Remaining elements of second array
    while (j < m) {

        if (unionArray.empty() ||
            unionArray.back() != arr2[j]) {

            unionArray.push_back(arr2[j]);
        }

        j++;
    }

    cout << "\nUnion of arrays:\n";

    for (int num : unionArray) {
        cout << num << " ";
    }

    return 0;
}