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

    int left = 0;
    int right = n - 1;

    while(left < right) {

        swap(arr[left], arr[right]);

        left++;
        right--;
    }

    cout << "\nReversed Array:\n";

    for(int num : arr)
        cout << num << " ";

    return 0;
}