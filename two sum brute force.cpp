#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n, target;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements:\n";

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter target: ";
    cin >> target;

    bool found = false;

    for(int i = 0; i < n; i++) {

        for(int j = i + 1; j < n; j++) {

            if(arr[i] + arr[j] == target) {

                cout << "\nIndices: " << i << " " << j;
                cout << "\nValues: " << arr[i]
                     << " + " << arr[j]
                     << " = " << target;

                found = true;
                break;
            }
        }

        if(found)
            break;
    }

    if(!found)
        cout << "\nNo pair found.";

    return 0;
}