#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    vector<int> temp;

    cout << "Enter elements:\n";

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    // Store non-zero elements
    for(int i = 0; i < n; i++) {

        if(arr[i] != 0)
            temp.push_back(arr[i]);

    }

    // Copy back
    for(int i = 0; i < temp.size(); i++)
        arr[i] = temp[i];

    // Fill remaining with zeros
    for(int i = temp.size(); i < n; i++)
        arr[i] = 0;

    cout << "\nArray after moving zeros:\n";

    for(int num : arr)
        cout << num << " ";

    return 0;
}