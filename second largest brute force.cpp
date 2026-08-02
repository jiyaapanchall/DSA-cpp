#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements:\n";

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    int largest = arr[n - 1];
    int secondLargest = -1;

    for(int i = n - 2; i >= 0; i--) {

        if(arr[i] != largest) {
            secondLargest = arr[i];
            break;
        }

    }

    cout << "Largest = " << largest << endl;

    if(secondLargest == -1)
        cout << "Second Largest Not Found";
    else
        cout << "Second Largest = " << secondLargest;

    return 0;
}