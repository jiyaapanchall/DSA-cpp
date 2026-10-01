#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isInterleave(string s1, string s2, string s3) {

    int n = s1.length();
    int m = s2.length();

    // Length must match
    if (n + m != s3.length()) {
        return false;
    }

    vector<vector<bool>> dp(
        n + 1,
        vector<bool>(m + 1, false)
    );

    // Empty strings form empty string
    dp[0][0] = true;

    for (int i = 1; i <= n; i++) {

        if (s1[i - 1] == s3[i - 1]) {
            dp[i][0] = dp[i - 1][0];
        }
    }

    for (int j = 1; j <= m; j++) {

        if (s2[j - 1] == s3[j - 1]) {
            dp[0][j] = dp[0][j - 1];
        }
    }

    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= m; j++) {

            int k = i + j - 1;

            // Take character from s1
            if (s1[i - 1] == s3[k]) {

                dp[i][j] =
                    dp[i][j] ||
                    dp[i - 1][j];
            }

            // Take character from s2
            if (s2[j - 1] == s3[k]) {

                dp[i][j] =
                    dp[i][j] ||
                    dp[i][j - 1];
            }
        }
    }

    return dp[n][m];
}

int main() {

    string s1 = "aab";
    string s2 = "axy";
    string s3 = "aaxaby";

    cout << boolalpha
         << isInterleave(s1, s2, s3);

    return 0;
}