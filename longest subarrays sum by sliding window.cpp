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

    int left = 0;
    int sum = 0;
    int maxLength = 0;

    for(int right = 0; right < n; right++) {

        sum += arr[right];

        while(sum > k && left <= right) {
            sum -= arr[left];
            left++;
        }

        if(sum == k) {
            maxLength = max(maxLength, right - left + 1);
        }
    }

    cout << "\nLongest subarray length = " << maxLength;

    return 0;
}