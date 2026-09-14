#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElement(vector<int>& arr) {
    int n = arr.size();

    vector<int> answer(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {

        // Remove elements that cannot be the answer
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }

        // If stack is empty, no greater element exists
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

    vector<int> result = nextGreaterElement(arr);

    cout << "Next Greater Elements: ";

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}