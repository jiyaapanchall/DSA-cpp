#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements:\n";

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    unordered_map<int, int> frequency;

    for(int num : arr) {

        frequency[num]++;

        if(frequency[num] > n / 2) {
            cout << "Majority Element = " << num;
            return 0;
        }
    }

    cout << "No majority element.";

    return 0;
}