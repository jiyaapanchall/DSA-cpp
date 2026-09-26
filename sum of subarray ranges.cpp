#include <iostream>
#include <vector>
using namespace std;

long long sumSubarrayRanges(vector<int>& nums) {

    int n = nums.size();

    long long sumMin = 0;
    long long sumMax = 0;

    vector<int> st;

    // ---------- SUM OF MINIMUMS ----------

    // Previous smaller
    vector<int> leftMin(n);

    for (int i = 0; i < n; i++) {

        while (!st.empty() && nums[st.back()] > nums[i]) {
            st.pop_back();
        }

        leftMin[i] = st.empty() ? -1 : st.back();

        st.push_back(i);
    }

    st.clear();

    // Next smaller or equal
    vector<int> rightMin(n);

    for (int i = n - 1; i >= 0; i--) {

        while (!st.empty() && nums[st.back()] >= nums[i]) {
            st.pop_back();
        }

        rightMin[i] = st.empty() ? n : st.back();

        st.push_back(i);
    }

    // Calculate minimum contribution
    for (int i = 0; i < n; i++) {

        long long left = i - leftMin[i];
        long long right = rightMin[i] - i;

        sumMin += 1LL * nums[i] * left * right;
    }

    // ---------- SUM OF MAXIMUMS ----------

    st.clear();

    // Previous greater
    vector<int> leftMax(n);

    for (int i = 0; i < n; i++) {

        while (!st.empty() && nums[st.back()] < nums[i]) {
            st.pop_back();
        }

        leftMax[i] = st.empty() ? -1 : st.back();

        st.push_back(i);
    }

    st.clear();

    // Next greater or equal
    vector<int> rightMax(n);

    for (int i = n - 1; i >= 0; i--) {

        while (!st.empty() && nums[st.back()] <= nums[i]) {
            st.pop_back();
        }

        rightMax[i] = st.empty() ? n : st.back();

        st.push_back(i);
    }

    // Calculate maximum contribution
    for (int i = 0; i < n; i++) {

        long long left = i - leftMax[i];
        long long right = rightMax[i] - i;

        sumMax += 1LL * nums[i] * left * right;
    }

    return sumMax - sumMin;
}

int main() {

    vector<int> nums = {1, 2, 3};

    cout << sumSubarrayRanges(nums);

    return 0;
}