#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements:\n";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int singleNumber = 0;

    for (int i = 0; i < n; i++) {
        singleNumber = singleNumber ^ arr[i];
    }

    cout << "\nNumber appearing only once = "
         << singleNumber;

    return 0;
}