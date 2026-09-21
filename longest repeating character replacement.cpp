#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int characterReplacement(string s, int k) {

    vector<int> frequency(26, 0);

    int left = 0;
    int maxFreq = 0;
    int maxLength = 0;

    for (int right = 0; right < s.length(); right++) {

        int index = s[right] - 'A';

        frequency[index]++;

        maxFreq = max(maxFreq, frequency[index]);

        int windowLength = right - left + 1;

        int replacements = windowLength - maxFreq;

        // Window is invalid
        while (replacements > k) {

            frequency[s[left] - 'A']--;

            left++;

            windowLength = right - left + 1;
            replacements = windowLength - maxFreq;
        }

        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}

int main() {

    string s = "AABABBA";
    int k = 1;

    cout << "Longest length: "
         << characterReplacement(s, k);

    return 0;
}