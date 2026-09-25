#include <iostream>
#include <string>
#include <vector>
using namespace std;

string removeDuplicateLetters(string s) {

    vector<int> frequency(26, 0);
    vector<bool> used(26, false);

    // Count frequency
    for (char c : s) {
        frequency[c - 'a']++;
    }

    string st;

    for (char c : s) {

        int index = c - 'a';

        frequency[index]--;

        // Already present in stack
        if (used[index])
            continue;

        // Remove larger characters if they appear later
        while (!st.empty() &&
               st.back() > c &&
               frequency[st.back() - 'a'] > 0) {

            used[st.back() - 'a'] = false;
            st.pop_back();
        }

        st.push_back(c);
        used[index] = true;
    }

    return st;
}

int main() {

    string s = "cbacdcbc";

    cout << removeDuplicateLetters(s);

    return 0;
}