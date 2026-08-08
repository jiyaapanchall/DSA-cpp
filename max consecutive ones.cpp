#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter binary array (0s and 1s):\n";

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int count = 0;
    int maxCount = 0;

    for(int i = 0; i < n; i++) {

        if(arr[i] == 1) {
            count++;
            maxCount = max(maxCount, count);
        }
        else {
            count = 0;
        }
    }

    cout << "\nMaximum consecutive 1s = " << maxCount;

    return 0;
}