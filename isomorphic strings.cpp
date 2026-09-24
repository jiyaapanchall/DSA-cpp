#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isIsomorphic(string s, string t) {

    if (s.length() != t.length())
        return false;

    vector<int> mapST(256, -1);
    vector<int> mapTS(256, -1);

    for (int i = 0; i < s.length(); i++) {

        char a = s[i];
        char b = t[i];

        // Check s -> t mapping
        if (mapST[a] != -1 && mapST[a] != b)
            return false;

        // Check t -> s mapping
        if (mapTS[b] != -1 && mapTS[b] != a)
            return false;

        mapST[a] = b;
        mapTS[b] = a;
    }

    return true;
}

int main() {

    string s = "egg";
    string t = "add";

    cout << (isIsomorphic(s, t) ? "true" : "false");

    return 0;
}