
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> ans;

    void backtrack(string& s,
                   int index,
                   int parts,
                   string& current) {

        // Four parts must consume the whole string
        if (parts == 4) {
            if (index == s.size()) {
                ans.push_back(current);
            }
            return;
        }

        // Try parts of length 1, 2, or 3
        for (int len = 1; len <= 3; len++) {

            if (index + len > s.size())
                break;

            string part = s.substr(index, len);

            // Leading zero is allowed only for "0"
            if (len > 1 && part[0] == '0')
                break;

            int value = stoi(part);

            // IP address part cannot exceed 255
            if (value > 255)
                break;

            int oldSize = current.size();

            // Add separator when needed
            if (parts > 0)
                current += ".";

            current += part;

            // Explore next part
            backtrack(s,
                      index + len,
                      parts + 1,
                      current);

            // Undo
            current.resize(oldSize);
        }
    }

    vector<string> restoreIpAddresses(string s) {
        if (s.size() < 4 || s.size() > 12)
            return {};

        string current;
        backtrack(s, 0, 0, current);

        return ans;
    }
};

int main() {
    string s = "25525511135";

    Solution sol;
    vector<string> result = sol.restoreIpAddresses(s);

    for (const string& ip : result)
        cout << ip << '\n';

    return 0;
}
