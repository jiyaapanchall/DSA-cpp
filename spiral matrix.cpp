#include <iostream>
#include <vector>
using namespace std;

int main() {

    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    cout << "Enter matrix elements:\n";

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    int top = 0;
    int bottom = rows - 1;
    int left = 0;
    int right = cols - 1;

    cout << "\nSpiral order:\n";

    while (top <= bottom && left <= right) {

        // 1. Left to Right
        for (int j = left; j <= right; j++) {
            cout << matrix[top][j] << " ";
        }

        top++;

        // 2. Top to Bottom
        for (int i = top; i <= bottom; i++) {
            cout << matrix[i][right] << " ";
        }

        right--;

        // 3. Right to Left
        if (top <= bottom) {

            for (int j = right; j >= left; j--) {
                cout << matrix[bottom][j] << " ";
            }

            bottom--;
        }

        // 4. Bottom to Top
        if (left <= right) {

            for (int i = bottom; i >= top; i--) {
                cout << matrix[i][left] << " ";
            }

            left++;
        }
    }

    return 0;
}