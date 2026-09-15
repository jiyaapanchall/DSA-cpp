#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> previousSmallerElement(vector<int>& arr) {
    int n = arr.size();

    vector<int> answer(n);
    stack<int> st;

    // Traverse from left to right
    for (int i = 0; i < n; i++) {

        // Remove elements that are not smaller
        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }

        // Find previous smaller element
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
    vector<int> arr = {4, 5, 2, 10, 8};

    vector<int> result = previousSmallerElement(arr);

    cout << "Previous Smaller Elements: ";

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}