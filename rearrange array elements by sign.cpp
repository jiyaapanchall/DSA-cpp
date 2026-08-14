#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    vector<int> result(n);

    cout << "Enter elements:\n";

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int positiveIndex = 0;
    int negativeIndex = 1;

    for(int i = 0; i < n; i++) {

        if(arr[i] > 0) {

            result[positiveIndex] = arr[i];
            positiveIndex += 2;

        }
        else {

            result[negativeIndex] = arr[i];
            negativeIndex += 2;

        }
    }

    cout << "\nRearranged array:\n";

    for(int num : result)
        cout << num << " ";

    return 0;
}