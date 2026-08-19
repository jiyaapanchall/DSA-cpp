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

    vector<int> intersection;

    int i = 0;
    int j = 0;

    while (i < n && j < m) {

        if (arr1[i] == arr2[j]) {

            intersection.push_back(arr1[i]);

            i++;
            j++;
        }
        else if (arr1[i] < arr2[j]) {

            i++;
        }
        else {

            j++;
        }
    }

    cout << "\nIntersection of arrays:\n";

    for (int num : intersection) {
        cout << num << " ";
    }

    return 0;
}