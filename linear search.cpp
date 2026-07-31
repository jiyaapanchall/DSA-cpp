#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter " << n << " elements:\n";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;

    cout << "\nEnter element to search: ";
    cin >> target;

    int index = -1;

    for (int i = 0; i < n; i++) {

        if (arr[i] == target) {
            index = i;
            break;
        }

    }

    if (index != -1)
        cout << "Element found at index " << index;
    else
        cout << "Element not found.";

    return 0;
}