#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> findAnagrams(string s, string p) {
    vector<int> result;

    if (p.length() > s.length())
        return result;

    vector<int> need(26, 0);
    vector<int> window(26, 0);

    // Frequency of characters in p
    for (char c : p) {
        need[c - 'a']++;
    }

    int k = p.length();

    // First window
    for (int i = 0; i < k; i++) {
        window[s[i] - 'a']++;
    }

    if (window == need)
        result.push_back(0);

    // Slide window
    for (int right = k; right < s.length(); right++) {

        // Add new character
        window[s[right] - 'a']++;

        // Remove old character
        window[s[right - k] - 'a']--;

        if (window == need)
            result.push_back(right - k + 1);
    }

    return result;
}

int main() {
    string s = "cbaebabacd";
    string p = "abc";

    vector<int> result = findAnagrams(s, p);

    for (int index : result) {
        cout << index << " ";
    }

    return 0;
}