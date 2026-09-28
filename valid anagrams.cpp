#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isAnagram(string s, string t) {

    if (s.length() != t.length())
        return false;

    vector<int> freq(26, 0);

    for (char c : s) {
        freq[c - 'a']++;
    }

    for (char c : t) {
        freq[c - 'a']--;
    }

    for (int count : freq) {
        if (count != 0)
            return false;
    }

    return true;
}

int main() {

    string s = "anagram";
    string t = "nagaram";

    if (isAnagram(s, t))
        cout << "true";
    else
        cout << "false";

    return 0;
}