#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    vector<int> reverseArr(n);

    cout << "Enter elements:\n";

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    for(int i = 0; i < n; i++)
        reverseArr[i] = arr[n - i - 1];

    cout << "\nReversed Array:\n";

    for(int num : reverseArr)
        cout << num << " ";

    return 0;
}