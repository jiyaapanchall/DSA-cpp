#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements:\n";

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int answer = 0;

    for(int i = 0; i < n; i++) {
        answer = answer ^ arr[i];
    }

    cout << "\nThe single number is: " << answer;

    return 0;
}