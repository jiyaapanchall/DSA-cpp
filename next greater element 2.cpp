#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();

    vector<int> answer(n, -1);
    stack<int> st;

    // Traverse the array twice
    for (int i = 2 * n - 1; i >= 0; i--) {

        int current = nums[i % n];

        // Remove elements that cannot be the answer
        while (!st.empty() && st.top() <= current) {
            st.pop();
        }

        // Only store answers for original indices
        if (i < n) {
            if (!st.empty()) {
                answer[i] = st.top();
            }
        }

        // Add current element to stack
        st.push(current);
    }

    return answer;
}

int main() {
    vector<int> nums = {1, 2, 1};

    vector<int> result = nextGreaterElements(nums);

    cout << "Next Greater Elements: ";

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}