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

    for(int num = 0; num <= n; num++) {

        bool found = false;

        for(int i = 0; i < n; i++) {

            if(arr[i] == num) {
                found = true;
                break;
            }

        }

        if(!found) {
            cout << "\nMissing Number = " << num;
            break;
        }

    }

    return 0;
}