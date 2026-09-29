#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int coinChange(vector<int>& coins, int amount) {

    const int INF = amount + 1;

    vector<int> dp(amount + 1, INF);

    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {

        for (int coin : coins) {

            if (coin <= i && dp[i - coin] != INF) {
                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
    }

    return dp[amount] == INF ? -1 : dp[amount];
}

int main() {

    vector<int> coins = {1, 2, 5};
    int amount = 11;

    cout << coinChange(coins, amount);

    return 0;
}