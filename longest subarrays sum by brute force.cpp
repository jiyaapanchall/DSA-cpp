#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n, k;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter positive elements:\n";

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter target K: ";
    cin >> k;

    int maxLength = 0;

    for(int i = 0; i < n; i++) {

        int sum = 0;

        for(int j = i; j < n; j++) {

            sum += arr[j];

            if(sum == k) {
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }

    cout << "\nLongest subarray length = " << maxLength;

    return 0;
}