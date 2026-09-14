#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextSmallerElement(vector<int>& arr) {
    int n = arr.size();

    vector<int> answer(n);
    stack<int> st;

    // Traverse from right to left
    for (int i = n - 1; i >= 0; i--) {

        // Remove elements that are not smaller
        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }

        // Find next smaller element
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
    vector<int> arr = {4, 8, 5, 2, 25};

    vector<int> result = nextSmallerElement(arr);

    cout << "Next Smaller Elements: ";

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}