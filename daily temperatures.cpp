#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();

    vector<int> answer(n, 0);
    stack<int> st;  // Stores indices

    for (int i = n - 1; i >= 0; i--) {

        // Remove temperatures that are not warmer
        while (!st.empty() &&
               temperatures[st.top()] <= temperatures[i]) {
            st.pop();
        }

        // If a warmer day exists
        if (!st.empty()) {
            answer[i] = st.top() - i;
        }

        // Store current index
        st.push(i);
    }

    return answer;
}

int main() {
    vector<int> temperatures = {
        73, 74, 75, 71, 69, 72, 76, 73
    };

    vector<int> result = dailyTemperatures(temperatures);

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}