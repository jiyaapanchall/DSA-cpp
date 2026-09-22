#include <iostream>
#include <string>
using namespace std;

int expandAroundCenter(string& s, int left, int right) {
    int count = 0;

    while (left >= 0 &&
           right < s.length() &&
           s[left] == s[right]) {

        count++;

        left--;
        right++;
    }

    return count;
}

int countSubstrings(string s) {
    int total = 0;

    for (int i = 0; i < s.length(); i++) {

        // Odd-length palindromes
        total += expandAroundCenter(s, i, i);

        // Even-length palindromes
        total += expandAroundCenter(s, i, i + 1);
    }

    return total;
}

int main() {
    string s = "aaa";

    cout << countSubstrings(s);

    return 0;
}