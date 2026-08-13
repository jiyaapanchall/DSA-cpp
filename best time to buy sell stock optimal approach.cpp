#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int n;

    cout << "Enter number of days: ";
    cin >> n;

    vector<int> prices(n);

    cout << "Enter stock prices:\n";

    for(int i = 0; i < n; i++)
        cin >> prices[i];

    int minPrice = prices[0];
    int maxProfit = 0;

    for(int i = 1; i < n; i++) {

        int profit = prices[i] - minPrice;

        maxProfit = max(maxProfit, profit);

        minPrice = min(minPrice, prices[i]);
    }

    cout << "\nMaximum Profit = " << maxProfit;

    return 0;
}