#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    const long long MOD = 1000000007;

    long long oneDigit(char c) {
        if (c == '*')
            return 9;

        if (c == '0')
            return 0;

        return 1;
    }

    long long twoDigits(char a, char b) {
        if (a == '*' && b == '*')
            return 15;

        if (a == '*') {
            if (b >= '0' && b <= '6')
                return 2;

            return 1;
        }

        if (b == '*') {
            if (a == '1')
                return 9;

            if (a == '2')
                return 6;

            return 0;
        }

        int num = (a - '0') * 10 + (b - '0');

        if (num >= 10 && num <= 26)
            return 1;

        return 0;
    }

    int numDecodings(string s) {
        int n = s.length();

        if (n == 0)
            return 0;

        long long prev2 = 1;
        long long prev1 = oneDigit(s[0]);

        if (prev1 == 0)
            return 0;

        for (int i = 1; i < n; i++) {
            long long current = 0;

            // Decode current character alone
            current += oneDigit(s[i]) * prev1;

            // Decode current character with previous character
            current += twoDigits(s[i - 1], s[i]) * prev2;

            current %= MOD;

            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};

int main() {
    Solution sol;

    string s = "1*";

    cout << sol.numDecodings(s);

    return 0;
}