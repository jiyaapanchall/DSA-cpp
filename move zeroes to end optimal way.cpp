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

    int j = 0;

    for(int i = 0; i < n; i++) {

        if(arr[i] != 0) {

            swap(arr[i], arr[j]);
            j++;

        }

    }

    cout << "\nArray after moving zeros:\n";

    for(int num : arr)
        cout << num << " ";

    return 0;
}