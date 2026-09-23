#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

string simplifyPath(string path) {

    vector<string> st;

    stringstream ss(path);
    string part;

    while (getline(ss, part, '/')) {

        // Empty part or current directory
        if (part.empty() || part == ".") {
            continue;
        }

        // Parent directory
        if (part == "..") {

            if (!st.empty()) {
                st.pop_back();
            }
        }

        // Normal directory
        else {
            st.push_back(part);
        }
    }

    // Build canonical path
    string result = "";

    for (string dir : st) {
        result += "/" + dir;
    }

    if (result.empty())
        return "/";

    return result;
}

int main() {

    string path = "/a/./b/../../c/";

    cout << simplifyPath(path);

    return 0;
}