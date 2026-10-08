#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:

    vector<string> ans;

    void backtrack(int n,
                   int open,
                   int close,
                   string& current) {

        // Complete valid combination
        if (current.size() == 2 * n) {
            ans.push_back(current);
            return;
        }

        // Add opening parenthesis
        if (open < n) {

            current.push_back('(');

            backtrack(n,
                      open + 1,
                      close,
                      current);

            current.pop_back();
        }

        // Add closing parenthesis
        if (close < open) {

            current.push_back(')');

            backtrack(n,
                      open,
                      close + 1,
                      current);

            current.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {

        string current;

        backtrack(n, 0, 0, current);

        return ans;
    }
};

int main() {

    int n = 3;

    Solution sol;

    vector<string> result =
        sol.generateParenthesis(n);

    for (string s : result)
        cout << s << endl;

    return 0;
}