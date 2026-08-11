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

    int candidate = 0;
    int count = 0;

    // Find candidate
    for(int num : arr) {

        if(count == 0)
            candidate = num;

        if(num == candidate)
            count++;
        else
            count--;
    }

    // Verify candidate
    count = 0;

    for(int num : arr) {

        if(num == candidate)
            count++;
    }

    if(count > n / 2)
        cout << "\nMajority Element = " << candidate;
    else
        cout << "\nNo majority element.";

    return 0;
}