#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n, k;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements:\n";

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter K: ";
    cin >> k;

    k = k % n;

    vector<int> temp;

    for(int i = 0; i < k; i++)
        temp.push_back(arr[i]);

    for(int i = k; i < n; i++)
        arr[i - k] = arr[i];

    for(int i = 0; i < k; i++)
        arr[n - k + i] = temp[i];

    cout << "\nArray after rotation:\n";

    for(int num : arr)
        cout << num << " ";

    return 0;
}