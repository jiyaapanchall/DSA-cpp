#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool checkInclusion(string s1, string s2) {
    if (s1.length() > s2.length())
        return false;

    vector<int> need(26, 0);
    vector<int> window(26, 0);

    // Frequency of s1
    for (char c : s1) {
        need[c - 'a']++;
    }

    int m = s1.length();

    // First window
    for (int i = 0; i < m; i++) {
        window[s2[i] - 'a']++;
    }

    if (window == need)
        return true;

    // Slide the window
    for (int right = m; right < s2.length(); right++) {

        // Add new character
        window[s2[right] - 'a']++;

        // Remove old character
        window[s2[right - m] - 'a']--;

        if (window == need)
            return true;
    }

    return false;
}

int main() {
    string s1 = "ab";
    string s2 = "eidbaooo";

    cout << (checkInclusion(s1, s2) ? "true" : "false");

    return 0;
}