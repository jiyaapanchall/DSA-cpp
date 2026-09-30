#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int minCut(string s) {

    int n = s.length();

    // isPalindrome[i][j] tells whether s[i...j] is palindrome
    vector<vector<bool>> isPalindrome(
        n, vector<bool>(n, false)
    );

    // Build palindrome table
    for (int i = n - 1; i >= 0; i--) {

        for (int j = i; j < n; j++) {

            if (s[i] == s[j] &&
                (j - i <= 1 || isPalindrome[i + 1][j - 1])) {

                isPalindrome[i][j] = true;
            }
        }
    }

    // dp[i] = minimum cuts for s[0...i]
    vector<int> dp(n, 0);

    for (int i = 0; i < n; i++) {

        if (isPalindrome[0][i]) {
            dp[i] = 0;
        }
        else {

            dp[i] = i;

            for (int j = 1; j <= i; j++) {

                if (isPalindrome[j][i]) {

                    dp[i] = min(
                        dp[i],
                        dp[j - 1] + 1
                    );
                }
            }
        }
    }

    return dp[n - 1];
}

int main() {

    string s = "aab";

    cout << minCut(s);

    return 0;
}