#include <iostream>
#include <string>
using namespace std;

string expandAroundCenter(string s, int left, int right) {
    while (left >= 0 &&
           right < s.length() &&
           s[left] == s[right]) {
        left--;
        right++;
    }

    return s.substr(left + 1, right - left - 1);
}

string longestPalindrome(string s) {
    if (s.length() <= 1)
        return s;

    string answer = "";

    for (int i = 0; i < s.length(); i++) {

        // Odd-length palindrome
        string odd = expandAroundCenter(s, i, i);

        // Even-length palindrome
        string even = expandAroundCenter(s, i, i + 1);

        if (odd.length() > answer.length())
            answer = odd;

        if (even.length() > answer.length())
            answer = even;
    }

    return answer;
}

int main() {
    string s = "babad";

    cout << longestPalindrome(s);

    return 0;
}