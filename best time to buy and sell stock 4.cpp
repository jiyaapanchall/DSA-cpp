#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(int k, vector<int>& prices) {

    int n = prices.size();

    if (n == 0 || k == 0) {
        return 0;
    }

    // If k is large enough, this becomes unlimited transactions
    if (k >= n / 2) {

        int profit = 0;

        for (int i = 1; i < n; i++) {

            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }

        return profit;
    }

    vector<int> buy(k + 1, -1000000000);
    vector<int> sell(k + 1, 0);

    for (int price : prices) {

        for (int transaction = 1;
             transaction <= k;
             transaction++) {

            buy[transaction] = max(
                buy[transaction],
                sell[transaction - 1] - price
            );

            sell[transaction] = max(
                sell[transaction],
                buy[transaction] + price
            );
        }
    }

    return sell[k];
}

int main() {

    int k = 2;

    vector<int> prices = {
        3, 3, 5, 0, 0, 3, 1, 4
    };

    cout << maxProfit(k, prices);

    return 0;
}