#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;

bool wordPattern(string pattern, string s) {

    stringstream ss(s);
    string word;

    vector<string> words;

    while (ss >> word) {
        words.push_back(word);
    }

    if (pattern.length() != words.size())
        return false;

    unordered_map<char, string> charToWord;
    unordered_map<string, char> wordToChar;

    for (int i = 0; i < pattern.length(); i++) {

        char c = pattern[i];
        string w = words[i];

        // Check pattern -> word
        if (charToWord.count(c) &&
            charToWord[c] != w) {
            return false;
        }

        // Check word -> pattern
        if (wordToChar.count(w) &&
            wordToChar[w] != c) {
            return false;
        }

        charToWord[c] = w;
        wordToChar[w] = c;
    }

    return true;
}

int main() {

    string pattern = "abba";
    string s = "dog cat cat dog";

    cout << (wordPattern(pattern, s) ? "true" : "false");

    return 0;
}