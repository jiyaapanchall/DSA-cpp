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

    int maxProfit = 0;

    for(int i = 0; i < n; i++) {

        for(int j = i + 1; j < n; j++) {

            int profit = prices[j] - prices[i];

            maxProfit = max(maxProfit, profit);
        }
    }

    cout << "\nMaximum Profit = " << maxProfit;

    return 0;
}