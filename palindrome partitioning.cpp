#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> result;
    vector<string> current;
    vector<vector<bool>> isPalindrome;

    void backtrack(string& s, int start) {
        // Entire string has been partitioned
        if (start == s.length()) {
            result.push_back(current);
            return;
        }

        for (int end = start; end < s.length(); end++) {

            if (isPalindrome[start][end]) {

                // Choose
                current.push_back(
                    s.substr(start, end - start + 1)
                );

                // Explore
                backtrack(s, end + 1);

                // Undo choice
                current.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.length();

        isPalindrome.assign(
            n,
            vector<bool>(n, false)
        );

        // Build palindrome table
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {

                if (s[i] == s[j] &&
                    (j - i <= 1 ||
                     isPalindrome[i + 1][j - 1])) {

                    isPalindrome[i][j] = true;
                }
            }
        }

        backtrack(s, 0);

        return result;
    }
};

int main() {
    Solution sol;

    string s = "aab";

    vector<vector<string>> answer =
        sol.partition(s);

    for (auto& partition : answer) {
        cout << "[ ";

        for (auto& str : partition) {
            cout << str << " ";
        }

        cout << "]\n";
    }

    return 0;
}