#include <iostream>
#include <vector>
using namespace std;

long long mergeAndCount(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;

    int i = low;
    int j = mid + 1;

    long long count = 0;

    while (i <= mid && j <= high) {

        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        }
        else {
            temp.push_back(arr[j]);

            // All remaining elements in left half
            // are greater than arr[j]
            count += (mid - i + 1);

            j++;
        }
    }

    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= high) {
        temp.push_back(arr[j]);
        j++;
    }

    for (int k = low; k <= high; k++) {
        arr[k] = temp[k - low];
    }

    return count;
}

long long mergeSortAndCount(vector<int>& arr, int low, int high) {

    if (low >= high)
        return 0;

    int mid = low + (high - low) / 2;

    long long count = 0;

    count += mergeSortAndCount(arr, low, mid);

    count += mergeSortAndCount(arr, mid + 1, high);

    count += mergeAndCount(arr, low, mid, high);

    return count;
}

long long countInversions(vector<int>& arr) {

    return mergeSortAndCount(arr, 0, arr.size() - 1);
}

int main() {

    vector<int> arr = {5, 3, 2, 4, 1};

    cout << "Number of inversions: "
         << countInversions(arr) << endl;

    return 0;
}