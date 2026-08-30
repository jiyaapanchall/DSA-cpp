#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n;

    cout << "Enter number of rows: ";
    cin >> n;

    vector<vector<int>> triangle;

    for (int i = 0; i < n; i++) {

        vector<int> row(i + 1, 1);

        for (int j = 1; j < i; j++) {

            row[j] = triangle[i - 1][j - 1]
                   + triangle[i - 1][j];
        }

        triangle.push_back(row);
    }

    cout << "\nPascal's Triangle:\n";

    for (int i = 0; i < n; i++) {

        for (int j = 0; j <= i; j++) {
            cout << triangle[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}