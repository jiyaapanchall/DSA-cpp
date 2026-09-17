#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> calculateSpan(vector<int>& prices) {
    int n = prices.size();

    vector<int> span(n);
    stack<int> st;  // Stores indices

    for (int i = 0; i < n; i++) {

        // Remove prices that are <= current price
        while (!st.empty() && prices[st.top()] <= prices[i]) {
            st.pop();
        }

        // No previous greater element
        if (st.empty()) {
            span[i] = i + 1;
        }
        else {
            // Previous greater element found
            span[i] = i - st.top();
        }

        // Store current index
        st.push(i);
    }

    return span;
}

int main() {
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};

    vector<int> result = calculateSpan(prices);

    cout << "Stock Span: ";

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}