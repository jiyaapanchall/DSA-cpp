#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

string minWindow(string s, string t) {

    if (t.empty() || s.empty()) {
        return "";
    }

    vector<int> need(128, 0);
    vector<int> window(128, 0);

    // Count required characters
    for (char c : t) {
        need[c]++;
    }

    int required = 0;

    for (int i = 0; i < 128; i++) {
        if (need[i] > 0) {
            required++;
        }
    }

    int formed = 0;

    int left = 0;

    int minLength = INT_MAX;
    int startIndex = 0;

    for (int right = 0; right < s.length(); right++) {

        char current = s[right];

        window[current]++;

        // This character has now reached its required frequency
        if (need[current] > 0 &&
            window[current] == need[current]) {

            formed++;
        }

        // Try shrinking the window
        while (formed == required) {

            int currentLength = right - left + 1;

            if (currentLength < minLength) {
                minLength = currentLength;
                startIndex = left;
            }

            char leftChar = s[left];

            window[leftChar]--;

            // Window is no longer satisfying this character
            if (need[leftChar] > 0 &&
                window[leftChar] < need[leftChar]) {

                formed--;
            }

            left++;
        }
    }

    if (minLength == INT_MAX) {
        return "";
    }

    return s.substr(startIndex, minLength);
}

int main() {

    string s = "ADOBECODEBANC";
    string t = "ABC";

    cout << "Minimum window: "
         << minWindow(s, t);

    return 0;
}