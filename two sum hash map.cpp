#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {

    int n, target;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements:\n";

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter target: ";
    cin >> target;

    unordered_map<int, int> mp;

    for(int i = 0; i < n; i++) {

        int needed = target - arr[i];

        if(mp.find(needed) != mp.end()) {

            cout << "\nIndices: "
                 << mp[needed] << " " << i;

            cout << "\nValues: "
                 << needed << " + "
                 << arr[i] << " = "
                 << target;

            return 0;
        }

        mp[arr[i]] = i;
    }

    cout << "\nNo pair found.";

    return 0;
}