#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements:\n";

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    for(int i = 0; i < n; i++) {

        if(arr[i] > largest) {

            secondLargest = largest;
            largest = arr[i];

        }

        else if(arr[i] > secondLargest && arr[i] != largest) {

            secondLargest = arr[i];

        }

    }

    cout << "Largest = " << largest << endl;

    if(secondLargest == INT_MIN)
        cout << "Second Largest Not Found";
    else
        cout << "Second Largest = " << secondLargest;

    return 0;
}