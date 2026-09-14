#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> previousGreaterElement(vector<int>& arr) {
    int n = arr.size();

    vector<int> answer(n);
    stack<int> st;

    // Traverse from left to right
    for (int i = 0; i < n; i++) {

        // Remove elements that cannot be previous greater
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }

        // Find previous greater element
        if (st.empty()) {
            answer[i] = -1;
        } else {
            answer[i] = st.top();
        }

        // Current element becomes a candidate
        st.push(arr[i]);
    }

    return answer;
}

int main() {
    vector<int> arr = {10, 5, 11, 6, 20};

    vector<int> result = previousGreaterElement(arr);

    cout << "Previous Greater Elements: ";

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}