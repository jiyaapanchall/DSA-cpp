#include <iostream>
#include <vector>
using namespace std;

long long sumSubarrayMins(vector<int>& arr) {

    int n = arr.size();
    const long long MOD = 1000000007;

    vector<int> left(n);
    vector<int> right(n);

    vector<int> st;

    // Previous smaller element
    for (int i = 0; i < n; i++) {

        while (!st.empty() && arr[st.back()] > arr[i]) {
            st.pop_back();
        }

        if (st.empty())
            left[i] = -1;
        else
            left[i] = st.back();

        st.push_back(i);
    }

    st.clear();

    // Next smaller or equal element
    for (int i = n - 1; i >= 0; i--) {

        while (!st.empty() && arr[st.back()] >= arr[i]) {
            st.pop_back();
        }

        if (st.empty())
            right[i] = n;
        else
            right[i] = st.back();

        st.push_back(i);
    }

    long long answer = 0;

    for (int i = 0; i < n; i++) {

        long long leftCount = i - left[i];
        long long rightCount = right[i] - i;

        long long contribution =
            (arr[i] * leftCount % MOD) * rightCount % MOD;

        answer = (answer + contribution) % MOD;
    }

    return answer;
}

int main() {

    vector<int> arr = {3, 1, 2, 4};

    cout << sumSubarrayMins(arr);

    return 0;
}