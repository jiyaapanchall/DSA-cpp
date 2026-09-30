#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rodCutting(vector<int>& price, int N) {

    vector<int> dp(N + 1, 0);

    for (int pieceLength = 1; pieceLength <= N; pieceLength++) {

        for (int length = pieceLength; length <= N; length++) {

            dp[length] = max(
                dp[length],
                price[pieceLength - 1] +
                dp[length - pieceLength]
            );
        }
    }

    return dp[N];
}

int main() {

    vector<int> price = {2, 5, 7, 8};

    int N = 4;

    cout << rodCutting(price, N);

    return 0;
}