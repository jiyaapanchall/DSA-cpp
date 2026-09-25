#include <iostream>
#include <string>
using namespace std;

string largestOddNumber(string num) {

    for (int i = num.size() - 1; i >= 0; i--) {

        int digit = num[i] - '0';

        if (digit % 2 == 1) {
            return num.substr(0, i + 1);
        }
    }

    return "";
}

int main() {

    string num = "35427";

    cout << largestOddNumber(num);

    return 0;
}