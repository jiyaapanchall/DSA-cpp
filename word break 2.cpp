#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {

public:

    unordered_set<string> words;

    // memo[start] = all sentences possible from start
    vector<vector<string>> memo;
    vector<bool> visited;

    vector<string> dfs(string& s, int start) {

        if (start == s.length()) {
            return {""};
        }

        if (visited[start]) {
            return memo[start];
        }

        visited[start] = true;

        vector<string> result;

        for (int end = start; end < s.length(); end++) {

            string word = s.substr(start, end - start + 1);

            // If current substring is a dictionary word
            if (words.count(word)) {

                vector<string> remaining =
                    dfs(s, end + 1);

                for (string sentence : remaining) {

                    if (sentence.empty()) {
                        result.push_back(word);
                    }
                    else {
                        result.push_back(
                            word + " " + sentence
                        );
                    }
                }
            }
        }

        memo[start] = result;

        return result;
    }

    vector<string> wordBreak(
        string s,
        vector<string>& wordDict
    ) {

        words = unordered_set<string>(
            wordDict.begin(),
            wordDict.end()
        );

        int n = s.length();

        memo.resize(n);
        visited.assign(n, false);

        return dfs(s, 0);
    }
};

int main() {

    Solution solution;

    string s = "catsanddog";

    vector<string> wordDict = {
        "cat",
        "cats",
        "and",
        "sand",
        "dog"
    };

    vector<string> answer =
        solution.wordBreak(s, wordDict);

    for (string sentence : answer) {
        cout << sentence << endl;
    }

    return 0;
}