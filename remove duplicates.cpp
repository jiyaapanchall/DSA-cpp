#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter sorted elements:\n";

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    if(n == 0) {
        cout << "Array is empty.";
        return 0;
    }

    int i = 0;

    for(int j = 1; j < n; j++) {

        if(arr[j] != arr[i]) {
            i++;
            arr[i] = arr[j];
        }

    }

    cout << "\nArray after removing duplicates:\n";

    for(int k = 0; k <= i; k++)
        cout << arr[k] << " ";

    cout << "\nNumber of unique elements = " << i + 1;

    return 0;
}