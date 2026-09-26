#include <iostream>
#include <string>
using namespace std;

string removeKdigits(string num, int k) {

    string st;

    for (char digit : num) {

        while (!st.empty() &&
               k > 0 &&
               st.back() > digit) {

            st.pop_back();
            k--;
        }

        st.push_back(digit);
    }

    // If removals are still left,
    // remove from the end
    while (k > 0 && !st.empty()) {
        st.pop_back();
        k--;
    }

    // Remove leading zeroes
    int start = 0;

    while (start < st.length() && st[start] == '0') {
        start++;
    }

    string result = st.substr(start);

    if (result.empty())
        return "0";

    return result;
}

int main() {

    string num = "1432219";
    int k = 3;

    cout << removeKdigits(num, k);

    return 0;
}