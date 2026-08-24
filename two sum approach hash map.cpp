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

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter target: ";
    cin >> target;

    unordered_map<int, int> seen;

    for (int i = 0; i < n; i++) {

        int needed = target - arr[i];

        if (seen.find(needed) != seen.end()) {

            cout << "\nPair found:\n";
            cout << arr[i] << " + " << needed
                 << " = " << target << endl;

            cout << "Indices: "
                 << seen[needed] << " and " << i;

            return 0;
        }

        seen[arr[i]] = i;
    }

    cout << "\nNo pair found.";

    return 0;
}