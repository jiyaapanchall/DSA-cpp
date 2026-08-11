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

    for(int i = 0; i < n; i++) {

        int count = 0;

        for(int j = 0; j < n; j++) {

            if(arr[i] == arr[j])
                count++;

        }

        if(count > n / 2) {
            cout << "Majority Element = " << arr[i];
            return 0;
        }
    }

    cout << "No majority element.";

    return 0;
}