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

    bool firstRowZero = false;
    bool firstColZero = false;

    // Check if first row contains zero
    for (int j = 0; j < cols; j++) {
        if (matrix[0][j] == 0) {
            firstRowZero = true;
        }
    }

    // Check if first column contains zero
    for (int i = 0; i < rows; i++) {
        if (matrix[i][0] == 0) {
            firstColZero = true;
        }
    }

    // Use first row and first column as markers
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {

            if (matrix[i][j] == 0) {

                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Set marked rows to zero
    for (int i = 1; i < rows; i++) {

        if (matrix[i][0] == 0) {

            for (int j = 1; j < cols; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    // Set marked columns to zero
    for (int j = 1; j < cols; j++) {

        if (matrix[0][j] == 0) {

            for (int i = 1; i < rows; i++) {
                matrix[i][j] = 0;
            }
        }
    }

    // Set first row to zero if needed
    if (firstRowZero) {

        for (int j = 0; j < cols; j++) {
            matrix[0][j] = 0;
        }
    }

    // Set first column to zero if needed
    if (firstColZero) {

        for (int i = 0; i < rows; i++) {
            matrix[i][0] = 0;
        }
    }

    cout << "\nMatrix after setting zeroes:\n";

    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}