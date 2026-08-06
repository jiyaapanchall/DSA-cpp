#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n, m;

    cout << "Enter size of first array: ";
    cin >> n;

    vector<int> arr1(n);

    cout << "Enter sorted elements of first array:\n";

    for(int i = 0; i < n; i++)
        cin >> arr1[i];

    cout << "\nEnter size of second array: ";
    cin >> m;

    vector<int> arr2(m);

    cout << "Enter sorted elements of second array:\n";

    for(int i = 0; i < m; i++)
        cin >> arr2[i];

    vector<int> result;

    int i = 0, j = 0;

    while(i < n && j < m) {

        if(arr1[i] < arr2[j]) {

            if(result.empty() || result.back() != arr1[i])
                result.push_back(arr1[i]);

            i++;
        }

        else if(arr1[i] > arr2[j]) {

            if(result.empty() || result.back() != arr2[j])
                result.push_back(arr2[j]);

            j++;
        }

        else {

            if(result.empty() || result.back() != arr1[i])
                result.push_back(arr1[i]);

            i++;
            j++;
        }
    }

    while(i < n) {

        if(result.empty() || result.back() != arr1[i])
            result.push_back(arr1[i]);

        i++;
    }

    while(j < m) {

        if(result.empty() || result.back() != arr2[j])
            result.push_back(arr2[j]);

        j++;
    }

    cout << "\nUnion of arrays:\n";

    for(int num : result)
        cout << num << " ";

    return 0;
}