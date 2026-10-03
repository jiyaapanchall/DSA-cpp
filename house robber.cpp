#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(vector<int>& prices, int fee) {
    int hold = -prices[0];
    int cash = 0;

    for (int i = 1; i < prices.size(); i++) {
        int prevHold = hold;
        int prevCash = cash;

        hold = max(prevHold, prevCash - prices[i]);
        cash = max(prevCash, prevHold + prices[i] - fee);
    }

    return cash;
}

int main() {
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;

    cout << maxProfit(prices, fee);

    return 0;
}