#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements in sorted order:\n";

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int target;

    cout << "\nEnter element to search: ";
    cin >> target;

    int low = 0;
    int high = n - 1;
    int index = -1;

    while(low <= high) {

        int mid = low + (high - low) / 2;

        if(arr[mid] == target) {
            index = mid;
            break;
        }

        else if(arr[mid] < target)
            low = mid + 1;

        else
            high = mid - 1;
    }

    if(index != -1)
        cout << "Element found at index " << index;
    else
        cout << "Element not found.";

    return 0;
}