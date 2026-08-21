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

    int missing = n;

    for (int i = 0; i < n; i++) {

        missing = missing ^ i;
        missing = missing ^ arr[i];
    }

    cout << "\nMissing number = " << missing;

    return 0;
}