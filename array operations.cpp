#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter " << n << " elements:\n";

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int sum = 0;
    int maximum = arr[0];
    int minimum = arr[0];

    for(int i = 0; i < n; i++) {

        sum += arr[i];

        if(arr[i] > maximum)
            maximum = arr[i];

        if(arr[i] < minimum)
            minimum = arr[i];
    }

    double average = (double)sum / n;

    cout << "\nArray Elements: ";

    for(int x : arr)
        cout << x << " ";

    cout << "\nSum = " << sum;
    cout << "\nAverage = " << average;
    cout << "\nMaximum = " << maximum;
    cout << "\nMinimum = " << minimum;

    return 0;
}