#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n;

    cout << "Enter value of n: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter " << n << " elements:\n";

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int expectedSum = n * (n + 1) / 2;
    int actualSum = 0;

    for(int i = 0; i < n; i++)
        actualSum += arr[i];

    cout << "\nMissing Number = " << expectedSum - actualSum;

    return 0;
}