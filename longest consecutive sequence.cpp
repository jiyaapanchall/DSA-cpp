#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {

    int n;

    cout << "Enter size: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements:\n";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_set<int> st;

    // Insert all elements
    for (int num : arr) {
        st.insert(num);
    }

    int longest = 0;

    for (int num : st) {

        // Start of sequence
        if (st.find(num - 1) == st.end()) {

            int current = num;
            int count = 1;

            while (st.find(current + 1) != st.end()) {

                current++;
                count++;
            }

            longest = max(longest, count);
        }
    }

    cout << "\nLongest consecutive sequence length = "
         << longest;

    return 0;
}