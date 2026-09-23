#include <iostream>
#include <vector>
using namespace std;

int compress(vector<char>& chars) {
    int n = chars.size();
    int write = 0;
    int i = 0;

    while (i < n) {
        char current = chars[i];
        int count = 0;

        // Count consecutive characters
        while (i < n && chars[i] == current) {
            i++;
            count++;
        }

        // Write the character
        chars[write++] = current;

        // Write count if greater than 1
        if (count > 1) {
            string num = to_string(count);

            for (char c : num) {
                chars[write++] = c;
            }
        }
    }

    return write;
}

int main() {
    vector<char> chars = {
        'a', 'a', 'b', 'b', 'c', 'c', 'c'
    };

    int length = compress(chars);

    cout << "Compressed: ";

    for (int i = 0; i < length; i++) {
        cout << chars[i] << " ";
    }

    cout << "\nLength: " << length;

    return 0;
}