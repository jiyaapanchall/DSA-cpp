#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements:\n";

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    bool sorted = true;

    for(int i = 0; i < n - 1; i++) {

        if(arr[i] > arr[i + 1]) {

            sorted = false;
            break;

        }

    }

    if(sorted)
        cout << "\nArray is sorted.";
    else
        cout << "\nArray is not sorted.";

    return 0;
}