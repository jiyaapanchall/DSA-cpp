#include <iostream>
#include <vector>
using namespace std;

int change(int amount, vector<int>& coins) {

    vector<int> dp(amount + 1, 0);

    dp[0] = 1;

    for (int coin : coins) {

        for (int x = coin; x <= amount; x++) {

            dp[x] += dp[x - coin];
        }
    }

    return dp[amount];
}

int main() {

    vector<int> coins = {1, 2, 5};
    int amount = 5;

    cout << change(amount, coins);

    return 0;
}