#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int lengthOfLongestSubstring(string s) {

    vector<int> lastSeen(256, -1);

    int left = 0;
    int maxLength = 0;

    for (int right = 0; right < s.length(); right++) {

        char current = s[right];

        // Character already exists inside current window
        if (lastSeen[current] >= left) {
            left = lastSeen[current] + 1;
        }

        // Update last position
        lastSeen[current] = right;

        // Calculate current window length
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}

int main() {

    string s = "abcabcbb";

    cout << "Longest substring length: "
         << lengthOfLongestSubstring(s);

    return 0;
}